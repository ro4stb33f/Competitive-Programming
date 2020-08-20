#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,w;
	cin >> n >> w;
	int mx = 100005;
	ll inf = 1e15;
	vector<vector<ll>> dp(n, vector<ll>(mx+1));
	for (int q = 0; q < n; q++)
	{
		ll weight, value;
		cin >> weight >> value;
		if (q == 0)
		{
			for (int e = 1; e <= value; e++)
			{
				dp[0][e] = weight;
			}
			for (int e = value+1; e <= mx; e++)
			{
				dp[0][e] = inf;
			}
		}
		else
		{
			for (int e = 0; e <= mx; e++)
			{
				dp[q][e] = dp[q-1][e];
			}
			for (int e = value; e <= mx; e++)
			{
				dp[q][e] = min(dp[q][e], weight + dp[q-1][e-value]);
			}
		}
	}
	for (int q = mx; q >= 0; q--)
	{
		if (dp[n-1][q] <= w)
		{
			cout << q << "\n";
			return 0;
		}
	}
	return 0;
}
