#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int md = 1e9+7;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> adj[n];
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		if (a==b)
		{
			continue;
		}
		adj[b].push_back(a);
	}
	vector<vector<int>> ans((1<<n), vector<int>(n));
	ans[1][0] = 1;
	for (int q = 3; q < (1<<n); q+=2)
	{
		for (int w = 0; w < n; w++)
		{
			if (((1<<w)&q) == 0)
			{
				continue;
			}
			int temp = (1<<w)^q;
			for (int e : adj[w])
			{
				ans[q][w] = (ans[q][w] + ans[temp][e]) % md;
			}
		}
	}
	cout << ans[(1<<n)-1][n-1] << "\n";
	return 0;
}
