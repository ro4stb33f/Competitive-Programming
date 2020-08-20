#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
set<int> adj[mx+1];
vector<int> adj1[mx+1];
vector<bool> visited(mx+1);
stack<int> tour;
void dfs(int v)
{
	visited[v] = true;
	for (int a : adj1[v])
	{
		if (!visited[a])
		{
			dfs(a);
		}
	}
}

void dfs2(int v)
{
	while (adj[v].size() > 0)
	{
		int a = *adj[v].begin();
		adj[v].erase(adj[v].begin());
		adj[a].erase(adj[a].find(v));
		dfs2(a);
	}
	tour.push(v);
}

int main()
{
	ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<int> degree(n+1);
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
		adj1[a].push_back(b);
		adj1[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	dfs(1);
	for (int q = 1; q <= n; q++)
	{
		if (!visited[q] && degree[q] > 0)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	for (int q = 1; q <= n; q++)
	{
		if (degree[q] % 2 == 1)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	dfs2(1);
	while (!tour.empty())
	{
		cout << tour.top() << " ";
		tour.pop();
	}
	cout << "\n";
	return 0;
}
