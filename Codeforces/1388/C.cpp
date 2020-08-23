#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e5;
vector<int> subtreesz(mx+1);
vector<int> vertexsz(mx+1);
vector<int> adj[mx+1];
void dfs(int v, int p)
{
	subtreesz[v] = vertexsz[v];
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a,v);
			subtreesz[v] += subtreesz[a];
		}
	}
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<ll> vertexval(n+1);
	for (int q = 1; q <= n; q++) adj[q].clear();
	for (int q = 1; q <= n; q++) cin >> vertexsz[q];
	for (int q = 1; q <= n; q++) cin >> vertexval[q];
	for (int q = 0; q < n-1; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	vector<bool> visited(n+1);
	queue<int> bfs;
	bfs.push(1);
	visited[1] = true;
	while (!bfs.empty())
	{
		int f = bfs.front();
		bfs.pop();
		if (vertexval[f] > subtreesz[f] || (((subtreesz[f] + vertexval[f]) % 2) + 2) % 2 == 1)
		{
			cout << "NO\n";
			return;
		}
		ll happy = (subtreesz[f] + vertexval[f])/2;
		ll sad = (subtreesz[f] - vertexval[f])/2;
		ll tothappy = 0, totsad = 0;
		for (int a : adj[f])
		{
			if (visited[a]) continue;
			visited[a] = true;
			if (vertexval[a] > subtreesz[a] || (((subtreesz[a] + vertexval[a]) % 2) + 2) % 2 == 1)
			{
				cout << "NO\n";
				return;
			}
			ll ahappy = (subtreesz[a] + vertexval[a])/2;
			ll asad = (subtreesz[a] - vertexval[a])/2;
			tothappy += ahappy;
			totsad += asad;
			bfs.push(a);
		}
		if (tothappy + totsad != subtreesz[f] - vertexsz[f] || tothappy > happy)
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
