#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int> adj[mx+1];
vector<int> radj[mx+1];
vector<int> topsort;
vector<bool> visited(mx+1);
vector<int> comp(mx+1);
int curcomp = 0;
void dfs(int v)
{
	visited[v] = true;
	for (int a : adj[v])
	{
		if (!visited[a])
		{
			dfs(a);
		}
	}
	topsort.push_back(v);
}

void dfs2(int v)
{
	visited[v] = true;
	for (int a : radj[v])
	{
		if (!visited[a])
		{
			dfs2(a);
		}
	}
	comp[v] = curcomp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
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
			dfs(q);
		}
	}
	reverse(topsort.begin(), topsort.end());
	fill(visited.begin(), visited.end(), false);
	for (int q = 0; q < n; q++)
	{
		if (comp[topsort[q]] == 0)
		{
			curcomp++;
			dfs2(topsort[q]);
		}
	}
	cout << curcomp << "\n";
	for (int q= 1; q <= n; q++)
	{
		cout << comp[q] << " ";
	}
	cout << "\n";
	return 0;
}
