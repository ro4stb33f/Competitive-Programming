#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<pair<int,int>> adj[mx+1];
vector<int> tour;
vector<bool> visited(2*mx+5);
void dfs(int v)
{
	while (adj[v].size() > 0)
	{
		int x = adj[v].back().first;
		int e = adj[v].back().second;
		visited[e] = true;
		adj[v].pop_back();
		dfs(x);
	}
	tour.push_back(v);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> indeg(n+1);
	vector<int> outdeg(n+1);
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].emplace_back(b,q);
		indeg[b]++;
		outdeg[a]++;
	}
	if (indeg[1]+1 != outdeg[1])
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	if (indeg[n]-1 != outdeg[n])
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int q = 2; q <= n-1; q++)
	{
		if (indeg[q] != outdeg[q])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	adj[0].emplace_back(1,m);
	adj[n].emplace_back(0,m+1);
	dfs(0);
	for (int q = 0; q < m; q++)
	{
		if (!visited[q])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	for (int q = tour.size()-2; q > 0; q--)
	{
		cout << tour[q] << " ";
	}
	cout << "\n";
	return 0;
}
