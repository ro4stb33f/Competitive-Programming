#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<int> adj[mx+1];
vector<int> par(mx+1);
vector<int> col(mx+1);
vector<int> nocol(mx+1);
void dfs(int v)
{
	int nocolans = 0;
	for (int a : adj[v])
	{
		if (a == par[v])
		{
			continue;
		}
		par[a] = v;
		dfs(a);
		nocolans += max(col[a], nocol[a]);
	}
	int colans = 0;
	for (int a : adj[v])
	{
		if (a == par[v])
		{
			continue;
		}
		int pos = nocolans - max(col[a], nocol[a])+nocol[a]+1;
		colans = max(pos, colans);
	}
	nocol[v] = nocolans;
	col[v] = colans;
}

int main()
{
	int n;
	cin >> n;
	for (int q = 0; q < n-1; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << max(col[1], nocol[1]) << "\n";
	return 0;
}
