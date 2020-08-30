#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld p;

ld plower(ll x, ll y)
{
	return (ld)(x * (x-1))/((x+y+1)*(x+y)) + (ld)((y+1)*x)/((x+y+1)*(x+y)) * 2 * p;
}

ld phigher(ll x, ll y)
{
	return (ld)(y * (y-1))/((x+y+1)*(x+y)) + (ld)((x+1)*y)/((x+y+1)*(x+y)) * 2 * (1.0-p);
}

void solve()
{
	cout << setprecision(15);
	ll n;
	cin >> n >> p;
	vector<vector<ld>> dp(n+1, vector<ld>(n+1));
	dp[0][0] = 0;
	for (ll q = 0; q <= n; q++)
	{
		for (ll w = 0; w <= n; w++)
		{
			if (q == 0 && w == 0) continue;
			dp[q][w] = 1;
			if (q > 0) dp[q][w] += plower(q,w) * dp[q-1][w];
			if (w > 0) dp[q][w] += phigher(q,w) * dp[q][w-1];
		}
	}
	for (ll q = 1; q <= n; q++)
	{
		cout << dp[q-1][n-q] << "\n";
	}
}

int main()
{
	freopen("elimination_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ":\n";
		solve();
	}
	return 0;
}
