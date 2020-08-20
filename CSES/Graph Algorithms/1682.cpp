#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int> comps[mx+1];
vector<int> topsort;
vector<int> adj[mx+1];
vector<int> radj[mx+1];
vector<bool> visited(mx+1);
int curcomp = 0;
int target;
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
	comps[curcomp].push_back(v);
}

bool dfs3(int v)
{
	visited[v] = true;
	for (int a : adj[v])
	{
		if (a == target)
		{
			return true;
		}
		if (!visited[a])
		{
			if (dfs3(a))
			{
				return true;
			}
		}
	}
	return false;
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
	fill(visited.begin(), visited.begin()+(n+1), false);
	for (int q = 0; q < n; q++)
	{
		if (!visited[topsort[q]])
		{
			curcomp++;
			dfs2(topsort[q]);
		}
	}
	if (curcomp == 1)
	{
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	int a = comps[1][0];
	int b = comps[2][0];
	fill(visited.begin(), visited.begin() + (n+1), false);
	target = b;
	if (dfs3(a))
	{
		cout << b << " " << a << "\n";
	}
	else
	{
		cout << a << " " << b << "\n";
	}
	return 0;
}
