#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> h(n);
	for (int q = 0; q < n; q++)
	{
		cin >> h[q];
	}
	int dp[n];
	dp[0]=0;
	for (int q = 1; q < n; q++)
	{
		dp[q] = dp[q-1] + abs(h[q] - h[q-1]);
		if (q-2 >= 0)
		{
			dp[q] = min(dp[q], dp[q-2] + abs(h[q] - h[q-2]));
		}
	}
	cout << dp[n-1] << "\n";
	return 0;
}
