#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	vector<int> last(10, -1);
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(10, vector<int>(10)));
	last[s[0]-'0']++;
	vector<int> ct(10);
	ct[s[0]-'0']++;
	for (int q = 1; q < n; q++)
	{
		ct[s[q]-'0']++;
		for (int w = 0; w < 10; w++)
		{
			for (int e = 0; e < 10; e++)
			{
				dp[q][w][e] = dp[q-1][w][e];
			}
		}
		int d = s[q]-'0';
		for (int w = 0; w < 10; w++)
		{
			int l = last[w];
			if (l == -1)
			{
				continue;
			}
			if (w == d)
			{
				if (l > 0)
				{
					dp[q][w][d] = max(dp[q][w][d], dp[l-1][w][d] + 1);
				}
				else
				{
					dp[q][w][d] = max(dp[q][w][d], 1);
				}
			}
			else
			{
				dp[q][w][d] = max(dp[q][w][d], dp[l][w][d]+1);
			}
		}
		last[d] = q;
	}
	int ans = 0;
	for (int q = 0; q < 10; q++)
	{
		if (ct[q] % 2 == 0)
		{
			ans = max(ans, ct[q]-1);
		}
		else
		{
			ans = max(ans, ct[q]);
		}
	}
	for (int q = 0; q < 10; q++)
	{
		for (int w = 0; w < 10; w++)
		{
			ans = max(ans, 2 * dp[n-1][q][w]);
		}
	}
	cout << (n-ans) << "\n";
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

