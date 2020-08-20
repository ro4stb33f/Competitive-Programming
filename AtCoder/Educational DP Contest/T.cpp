#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	ll dp[n+1][n+1];
	dp[1][1] = 1;
	for (int q = 2; q <= n; q++)
	{
		if (s[q-2] == '>')
		{
			dp[q][q] = 0;
			for (int w = q-1; w >= 1; w--)
			{
				dp[q][w] = (dp[q][w+1] + dp[q-1][w]) % md;
			}
		}
		else
		{
			dp[q][1] = 0;
			for (int w = 2; w <= q; w++)
			{
				dp[q][w] = (dp[q][w-1] + dp[q-1][w-1]) % md;
			}
		}
	}
	ll tot = 0;
	for (int q = 1; q <= n; q++)
	{
		tot = (tot + dp[n][q]) % md;
	}
	cout << tot <<"\n";
	return 0;
}

