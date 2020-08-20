#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;

int main()
{
	int n;
	cin >> n;
	int matching[n][n];
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			cin >> matching[q][w];
		}
	}
	ll dp[1<<n];
	dp[0] = 1;
	for (int q = 1; q < (1<<n); q++)
	{
		dp[q] = 0;
		int m = __builtin_popcount(q);
		for (int w = 0; w < n; w++)
		{
			if ((q & (1 << w)) > 0)
			{
				if (matching[w][m-1] == 1)
				{
					dp[q] = (dp[q] + dp[q ^ (1 << w)]) % md;
				}
			}
		}
	}
	cout << dp[(1<<n)-1] << "\n";
	return 0;
}
