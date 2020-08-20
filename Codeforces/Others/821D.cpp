#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
vector<int> dx = {-1,0};
vector<int> dy = {0,-1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	map<pair<int,int>,int> ma;
	for (int q = 0; q < k; q++)
	{
		int a,b;
		cin >> a >> b;
		ma[{a,b}] = q;
	}
	vector<vector<pair<int,int>>> adj(k+n+m+1);
	auto it = ma.begin();
	while (it != ma.end())
	{
		int i = it->second, r,c;
		tie(r,c) = it->first;
		for (int q = 0; q < 2; q++)
		{
			int nr = r+dx[q];
			int nc = c+dy[q];
			auto it1 = ma.find({nr,nc});
			if (it1 != ma.end())
			{
				adj[i].emplace_back(it1->second,0);
				adj[it1->second].emplace_back(i,0);
			}
		}
		adj[k-1+r].emplace_back(i,0);
		adj[k-1+n+c].emplace_back(i,0);
		adj[i].emplace_back(k-1+r,1);
		adj[i].emplace_back(k-1+n+c,1);
		if (r > 1)
		{
			adj[i].emplace_back(k-1+r-1,1);
			adj[k-1+r-1].emplace_back(i,0);
		}
		if (r < n)
		{
			adj[i].emplace_back(k-1+r+1,1);
			adj[k-1+r+1].emplace_back(i,0);
		}
		if (c > 1)
		{
			adj[i].emplace_back(k-1+n+c-1,1);
			adj[k-1+n+c-1].emplace_back(i,0);
		}
		if (c < m)
		{
			adj[i].emplace_back(k-1+n+c+1,1);
			adj[k-1+n+c+1].emplace_back(i,0);
		}
		it++;
	}
	int s = ma[{1,1}], e;
	auto it2 = ma.find({n,m});
	if (it2 != ma.end())
	{
		e = it2->second;
	}
	else
	{
		e = k+n+m;
		adj[k+n-1].emplace_back(e,0);
		adj[k+n+m-1].emplace_back(e,0);
	}
	vector<int> dist(k+n+m+1,inf);
	vector<bool> visited(k+n+m+1);
	dist[s] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({-dist[s],s});
	while (!pq.empty())
	{
		int v = pq.top().second;
		pq.pop();
		if (visited[v]) continue;
		visited[v] = true;
		for (auto edge : adj[v])
		{
			int a,d;
			tie(a,d) = edge;
			if (dist[v]+d < dist[a])
			{
				dist[a] = dist[v]+d;
				pq.push({-dist[a],a});
			}
		}
	}
	cout << (dist[e] == inf ? -1 : dist[e]) << "\n";
	return 0;
}
