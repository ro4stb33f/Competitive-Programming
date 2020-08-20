#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> h(n);
	for (int q = 0; q < n; q++)
	{
		cin >> h[q];
	}
	int dp[n];
	dp[0] = 0;
	for (int q = 1; q < n; q++)
	{
		dp[q] = dp[q-1] + abs(h[q] - h[q-1]);
		for (int w = 2; w <= k && q-w>= 0; w++)
		{
			dp[q] = min(dp[q], dp[q-w] + abs(h[q] - h[q-w]));
		}
	}
	cout << dp[n-1] << "\n";
	return 0;
}
