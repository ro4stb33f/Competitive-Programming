#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n;
	cin >> n;
	int val = 2*n;
	vector<int> a(val+10);
	for (int q = 0; q < val; q++)
	{
		cin >> a[q];
	}
	vector<int> sz;
	int lptr = 0;
	int curct = 1;
	int largestseen = a[0];
	for (int q = 1; q < 2*n; q++)
	{
		if (a[q] < a[q-1])
		{
			curct++;
			continue;
		}
		if (a[q] < largestseen)
		{
			curct++;
			continue;
		}
		sz.push_back(curct);
		curct = 1;
		lptr = q;
		largestseen = a[q];
	}
	sz.push_back(curct);
	int len = sz.size();
	vector<vector<bool>> dp(n+1, vector<bool>(len+1));
	dp[0][0] = true;
	for (int q = 1; q <= len; q++)
	{
		int x = sz[q-1];
		for (int w = 0; w <= n; w++)
		{
			if (dp[w][q-1])
			{
				dp[w][q] = true;
			}
			if (dp[w][q-1] == true && w+x <= n)
			{
				dp[w+x][q] = true;
			}
		}
	}
	for (int q = 1; q <= len; q++)
	{
		if (dp[n][q] == true)
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

