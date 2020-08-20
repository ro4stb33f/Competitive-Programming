#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e17;
const int mx = 1e5;
const ll md = 1e9+7;
vector<int> actualadj[mx+1];
vector<int> actualradj[mx+1];
vector<int> visited(mx+1);
vector<int> topsort;
void dfs(int v)
{
	visited[v] = 1;
	for (int a : actualadj[v])
	{
		if (visited[a] == 0)
		{
			dfs(a);
		}
	}
	visited[v] = 2;
	topsort.push_back(v);
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,ll>> adj[n+1];
	vector<int> radj[n+1];
	for (int q = 0; q < m; q++)
	{
		int a,b;
		ll c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b,c);
	}
	priority_queue<pair<ll,int>> pq;
	vector<ll> dist(n+1, INF);
	vector<bool> processed(n+1);
	dist[1] = 0;
	pq.push({0,1});
	while (!pq.empty())
	{
		int v = pq.top().second;
		pq.pop();
		if (processed[v])
		{
			continue;
		}
		processed[v] = true;
		for (auto e : adj[v])
		{
			int a;
			ll d;
			tie(a,d) = e;
			if (dist[v] + d < dist[a])
			{
				dist[a] = dist[v]+d;
				pq.push({-dist[a], a});
			}
		}
	}
	for (int q = 1; q <= n; q++)
	{
		if (dist[q] != INF)
		{
			for (auto e : adj[q])
			{
				int v;
				ll d;
				tie(v,d) = e;
				if (dist[q]+d==dist[v])
				{
					actualadj[q].push_back(v);
					actualradj[v].push_back(q);
				}
			}
		}
	}
	dfs(1);
	reverse(topsort.begin(), topsort.end());
	vector<ll> minedges(n+1, INF);
	vector<ll> maxedges(n+1);
	vector<ll> nummin(n+1);
	nummin[1] = 1;
	minedges[1] = 0;
	int sz = topsort.size();
	for (int q = 0; q < sz; q++)
	{
		for (int a : actualradj[topsort[q]])
		{
			minedges[topsort[q]] = min(minedges[topsort[q]], minedges[a]+1);
			maxedges[topsort[q]] = max(maxedges[topsort[q]], maxedges[a]+1);
			nummin[topsort[q]] = (nummin[topsort[q]]+nummin[a]) % md;
		}
	}
	cout << dist[n] << " " << nummin[n] << " " << minedges[n] << " " << maxedges[n] << "\n";
	return 0;
}
