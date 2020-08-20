#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int> adj[mx+1];
int ccstart = -1, ccend = -1;
vector<int> par(mx+1);
vector<int> visited(mx+1);

void dfs(int v)
{
	visited[v] = 1;
	for (int a : adj[v])
	{
		if (visited[a] == 1)
		{
			ccstart = a;
			ccend = v;
			return;
		}
		else
		{
			par[a] = v;
			dfs(a);
			if (ccstart != -1)
			{
				return;
			}
		}
	}
	visited[v] = 2;
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
	}
	for (int q = 1; q <= n; q++)
	{
		if (visited[q] == 0)
		{
			dfs(q);
		}
		if (ccstart != -1)
		{
			break;
		}
	}
	if (ccstart == -1)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> cycle;
	cycle.push_back(ccstart);
	int cur = ccend;
	while (cur != ccstart)
	{
		cycle.push_back(cur);
		cur = par[cur];
	}
	cycle.push_back(ccstart);
	reverse(cycle.begin(), cycle.end());
	cout << cycle.size() << "\n";
	for (int q : cycle)
	{
		cout << q << " ";
	}
	cout << "\n";
	return 0;
}
