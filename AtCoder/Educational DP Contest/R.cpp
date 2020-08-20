#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;

int main()
{
	ll n,k;
	cin >> n >> k;
	int edge[n+1][n+1];
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			cin >> edge[q][w];
		}
	}
	ll binpaths[n+1][n+1][62];
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			if (edge[q][w] == 1)
			{
				binpaths[q][w][0] = 1;
			}
			else
			{
				binpaths[q][w][0] = 0;
			}
		}
	}
	for (int r = 1; r < 62; r++)
	{
		for (int q = 1; q <= n; q++)
		{
			for (int w = 1; w <= n; w++)
			{
				binpaths[q][w][r] = 0;
				for (int e = 1; e <= n; e++)
				{
					binpaths[q][w][r] = (binpaths[q][w][r] + ((binpaths[q][e][r-1] * binpaths[e][w][r-1]) % md)) % md;
				}
			}
		}
	}
	ll dp[n+1][n+1][62];
	int cur = 0;
	while (true)
	{
		if (((1LL << cur) & k) > 0)
		{
			break;
		}
		cur++;
	}
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			dp[q][w][cur] = binpaths[q][w][cur];
		}
	}
	cur++;
	while ((1LL << cur) <= k)
	{
		if (((1LL << cur) & k) > 0)
		{
			for (int q = 1; q <= n; q++)
			{
				for (int w = 1; w <= n; w++)
				{
					dp[q][w][cur] = 0;
					for (int e = 1; e <= n; e++)
					{
						dp[q][w][cur] = (dp[q][w][cur] + ((dp[q][e][cur-1] * binpaths[e][w][cur]) % md)) % md;
					}
				}
			}
		}
		else
		{
			for (int q = 1; q <= n; q++)
			{
				for (int w = 1; w <= n; w++)
				{
					dp[q][w][cur] = dp[q][w][cur-1];
				}
			}
		}
		cur++;
	}
	ll tot = 0;
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			tot = (tot + dp[q][w][cur-1]) % md;
		}
	}
	cout << tot << "\n";
	return 0;
}
