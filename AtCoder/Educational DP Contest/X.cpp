#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 2e4;
int main()
{
	int n;
	cin >> n;
	vector<tuple<ll,ll,ll>> blocks;
	for (int q = 0; q < n; q++)
	{
		ll w,s,v;
		cin >> w >> s >> v;
		blocks.emplace_back(w,s,v);
	}
	sort(blocks.begin(), blocks.end(), [](tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){return (get<0>(a)+get<1>(a)) < (get<0>(b)+get<1>(b));});
	vector<vector<ll>> dp(n+1, vector<ll>(mx+1));
	for (int q = 0; q < n; q++)
	{
		for (int w = 1; w <= mx; w++)
		{
			ll w1 = get<0>(blocks[q]), s1 = get<1>(blocks[q]), v1 = get<2>(blocks[q]);
			dp[q+1][w]=max(dp[q][w], dp[q+1][w-1]);
			if (w >= w1 && s1 >= w-w1)
			{
				dp[q+1][w]=max(dp[q+1][w], dp[q][w-w1]+v1);
			}
		}
	}
	cout << dp[n][mx] << "\n";
	return 0;
}
