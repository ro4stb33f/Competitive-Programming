#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,w;
	cin >> n >> w;
	vector<vector<ll>> dp(n, vector<ll>(w+1));
	for (int q = 0; q < n; q++)
	{
		ll weight,value;
		cin >> weight >> value;
		if (q == 0)
		{
			for (int e = weight; e <= w; e++)
			{
				dp[q][e] = value;
			}
		}
		else
		{
			for (int e = 0; e <= w; e++)
			{
				dp[q][e] = dp[q-1][e];
				if (e >= weight)
				{
					dp[q][e] = max(dp[q][e], value+dp[q-1][e-weight]);
				}
			}
		}
	}
	cout << dp[n-1][w] << "\n";
	return 0;
}
