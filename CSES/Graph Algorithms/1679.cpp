#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int> adj[mx+1];
vector<int> ans;
vector<int> visited(mx+1);
bool impossible = false;

void dfs(int v)
{
	visited[v] = 1;
	for (int a : adj[v])
	{
		if (visited[a] == 1)
		{
			impossible= true;
			return;
		}
	}
	for (int a : adj[v])
	{
		if (visited[a] == 0)
		{
			dfs(a);
			if (impossible)
			{
				return;
			}
		}
	}
	visited[v] = 2;
	ans.push_back(v);
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
		if (impossible)
		{
			break;
		}
	}
	if (impossible)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	reverse(ans.begin(), ans.end());
	for (int q : ans)
	{
		cout << q << " ";
	}
	cout << "\n";
	return 0;
}
