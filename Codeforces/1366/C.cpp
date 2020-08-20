#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<ll>> nums(n+m-1, vector<ll>(2));
	for (int q= 0; q < n; q++)
	{
		for (int w = 0; w < m; w++)
		{
			int a;
			cin >> a;
			nums[q+w][a]++;
		}
	}
	ll tot = 0;
	for (int q = 0; q <= ((n+m-2)/2); q++)
	{
		int w = n+m-2-q;
		if (q >= w)
		{
			continue;
		}
		ll ct0 = 0, ct1 = 0;
		ct0 += nums[q][0];
		ct1 += nums[q][1];
		if (q < w)
		{
			ct0 += nums[w][0];
			ct1 += nums[w][1];
		}
		tot += min(ct0, ct1);
	}
	cout << tot << "\n";
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
