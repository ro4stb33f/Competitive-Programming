#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<double> p(n+1);
	for (int q = 1; q <= n; q++)
	{
		cin >> p[q];
	}
	vector<vector<double>> dp(n+1, vector<double>(n+1));
	dp[0][0] = 1;
	for (int q = 1; q <= n; q++)
	{
		dp[q][0] = dp[q-1][0] * (1-p[q]);
		for (int w = 1; w <= n; w++)
		{
			dp[q][w] = dp[q-1][w] * (1-p[q]) + dp[q-1][w-1] * p[q];
		}
	}
	double prob = 0;
	for (int q = n/2+1; q <= n; q++)
	{
		prob += dp[n][q];
	}
	printf("%.10f\n", prob);
	return 0;
}
