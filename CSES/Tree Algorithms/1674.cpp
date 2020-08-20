#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<int> adj[mx+1];
vector<int> child(mx+1);

void dfs(int v)
{
	int tot = 0;
	for (int a : adj[v])
	{
		dfs(a);
		tot+=(child[a]+1);
	}
	child[v] = tot;
}

int main()
{
	int n;
	cin >> n;
	for (int q = 2; q <= n; q++)
	{
		int p;
		cin >> p;
		adj[p].push_back(q);
	}
	dfs(1);
	for (int q = 1; q <= n; q++)
	{
		cout << child[q] << " ";
	}
	cout << "\n";
	return 0;
}
