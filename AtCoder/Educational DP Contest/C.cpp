#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(3));
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < 3; w++)
		{
			cin >> a[q][w];
		}
	}
	vector<vector<int>> dp(n, vector<int>(3));
	for (int q = 0; q < 3; q++)
	{
		dp[0][q] = a[0][q];
	}
	for (int q = 1; q < n; q++)
	{
		for (int w = 0; w < 3; w++)
		{
			dp[q][w] = 0;
			for (int e = 0; e < 3; e++)
			{
				if (w != e)
				{
					dp[q][w] = max(dp[q][w], dp[q-1][e]);
				}
			}
			dp[q][w] += a[q][w];
		}
	}
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";
	return 0;
}
