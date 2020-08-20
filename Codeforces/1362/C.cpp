#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
vector<ll> dp(62);

void solve()
{
	ll n;
	cin >> n;
	ll cur = 0;
	while ((1LL << cur) <= n)
	{
		cur++;
	}
	cur--;
	ll tot = 0;
	for (ll q = cur; q >= 1; q--)
	{
		if (((1LL << q) & n) != 0)
		{
			if (q > 0)
			{
				tot += dp[q-1];
				tot+=(q+1);
			}
		}
	}
	if (n % 2 == 1)
	{
		tot++;
	}
	cout << tot << "\n";
}

int main()
{
	int t;
	cin >> t;
	dp[0] = 1;
	for (ll q = 1; q < 62; q++)
	{
		dp[q] = 2 * dp[q-1] + (q+1);
	}
	while (t--)
	{
		solve();
	}
	return 0;
}
