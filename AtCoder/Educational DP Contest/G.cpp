#include <bits/stdc++.h>
using namespace std;
const int mx = 100005;
vector<int> adj[mx];
vector<int> radj[mx];
vector<int> sorted;
vector<bool> visited(mx);


void dfs(int v, int p)
{
	if (visited[v])
	{
		return;
	}
	visited[v] = true;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a, v);
		}
	}
	sorted.push_back(v);
}
int main()
{
	int n,m;
	cin >> n >> m;
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	for (int q = 1; q <= n; q++)
	{
		if (!visited[q])
		{
			dfs(q, -1);
		}
	}
	reverse(sorted.begin(), sorted.end());
	int dp[n];
	int best = 0;
	for (int q = 0; q < n; q++)
	{
		dp[sorted[q]] = 0;
		for (int a : radj[sorted[q]])
		{
			dp[sorted[q]] = max(dp[sorted[q]], dp[a]+1);
		}
		best = max(best, dp[sorted[q]]);
	}
	cout << best << "\n";
	return 0;
}
