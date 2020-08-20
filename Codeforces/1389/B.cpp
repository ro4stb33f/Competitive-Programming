#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n,k,z;
	cin >> n >> k >> z;
	vector<ll> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	vector<vector<vector<ll>>> dp(k+1, vector<vector<ll>>(z+1, vector<ll>(2)));
	dp[0][0][0] = a[0];
	dp[1][0][0] = a[0]+a[1];
	for (int q = 2; q <= k; q++)
	{
		dp[q][0][0] = dp[q-1][0][0]+a[q];
		for (int w = 1; w <= min(q/2, z); w++)
		{
			int rights = q-w;
			int pos = rights-w;
			dp[q][w][0] = 0;
			dp[q][w][1] = 0;
			if (w <= (q-1)/2)
			{
				dp[q][w][0] = max(dp[q-1][w][0], dp[q-1][w][1]) + a[pos];
			}
			if ((w-1) <= (q-1)/2)
			{
				dp[q][w][1] = max(dp[q][w][1], dp[q-1][w-1][0]+a[pos]);
			}
		}
	}
	ll ans = 0;
	for (int q = 0; q <= z; q++)
	{
		for (int w = 0; w <= 1; w++)
		{
			ans = max(ans, dp[k][q][w]);
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

