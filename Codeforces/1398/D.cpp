#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> sz(3);
	vector<vector<ll>> colors(3);
	cin >> sz[0] >> sz[1] >> sz[2];
	for (int q = 0; q < 3; q++)
	{
		for (int w = 0; w < sz[q]; w++)
		{
			int a;
			cin >> a;
			colors[q].push_back(a);
		}
		sort(colors[q].begin(), colors[q].end());
	}
	ll dp[sz[0]+1][sz[1]+1][sz[2]+1];
	for (int q = 0; q <= sz[0]; q++)
	{
		for (int w = 0; w <= sz[1]; w++)
		{
			for (int e = 0; e <= sz[2]; e++)
			{
				dp[q][w][e] = 0;
				if (q > 0)
				{
					if (w > 0)
					{
						dp[q][w][e] = max(dp[q][w][e], dp[q-1][w-1][e] + colors[0][q-1] * colors[1][w-1]);
					}
					if (e > 0)
					{
						dp[q][w][e] = max(dp[q][w][e], dp[q-1][w][e-1]+colors[0][q-1] * colors[2][e-1]);
					}
				}
				if (w > 0 && e > 0)
				{
					dp[q][w][e] = max(dp[q][w][e], dp[q][w-1][e-1]+colors[1][w-1]*colors[2][e-1]);
				}
			}
		}
	}
	cout << dp[sz[0]][sz[1]][sz[2]] << "\n";
	return 0;
}
