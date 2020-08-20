#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1000000007;

int main()
{
	int h,wi;
	cin >> h >> wi;
	string grid[h];
	for (int q = 0; q < h; q++)
	{
		cin >> grid[q];
	}
	ll dp[h][wi];
	dp[0][0] = 1;
	for (int q = 0; q < h; q++)
	{
		for (int w = 0; w < wi; w++)
		{
			if (q == 0 && w == 0)
			{
				continue;
			}
			dp[q][w] = 0;
			if (grid[q][w] == '#')
			{
				continue;
			}
			if (q > 0)
			{
				dp[q][w] = (dp[q][w] + dp[q-1][w]) % md;
			}
			if (w > 0)
			{
				dp[q][w] = (dp[q][w] + dp[q][w-1]) % md;
			}
		}
	}
	cout << dp[h-1][wi-1] << "\n";
	return 0;
}
