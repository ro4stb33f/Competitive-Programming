#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	int a[n];
	for (int q = 0; q < n; q++) cin >> a[q];
	vector<vector<int>> dp(n+1, vector<int>(2));
	dp[n-1][0] = a[n-1];
	dp[n-1][1] = 0;
	for (int q = n-2; q >= 0; q--)
	{
		dp[q][0] = dp[q+1][1] + a[q];
		if (q+2 <= n) dp[q][0] = min(dp[q][0], dp[q+2][1] + a[q]+a[q+1]);
		dp[q][1] = dp[q+1][0];
		if (q+2 <= n) dp[q][1] = min(dp[q][1], dp[q+2][0]);
	}
	cout << dp[0][0] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
