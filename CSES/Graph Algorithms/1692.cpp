#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int> adj[mx+1];
vector<int> tour;
void dfs(int v)
{
	while (adj[v].size() > 0)
	{
		int x = adj[v].back();
		adj[v].pop_back();
		dfs(x);
	}
	tour.push_back(v);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int q = 0; q < (1<<(n-1)); q++)
	{
		int x = q;
		if (q >= (1<<(n-2)))
		{
			x -= (1<<(n-2));
		}
		for (int w = 0; w < 2; w++)
		{
			adj[q].push_back(2*x+w);
		}
	}
	dfs(0);
	for (int q = 0; q < n-1; q++)
	{
		cout << "0";
	}
	int sz = tour.size();
	for (int q = sz-2; q >= 0; q--)
	{
		cout << (tour[q]%2);
	}
	cout << "\n";
	return 0;
}
