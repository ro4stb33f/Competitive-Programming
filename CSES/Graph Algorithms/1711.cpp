#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 510;
struct Dinic{
	int n, s, t; //# vertices, source, sink
	struct Edge{
		int to, rev; //to vertex, index of reverse edge in adj list
		ll flo, cap; //flow, capacity
	};
	vector<Edge> adj[sz];
	int level[sz];
	vector<Edge>::iterator cur[sz];
	void addedge(int u, int v, ll cap)
	{
		Edge a{v, (int)(adj[v].size()), 0, cap};
		Edge b{u, (int)(adj[u].size()), 0, 0};
		adj[u].push_back(a);
		adj[v].push_back(b);
	}
	bool bfs()
	{
		for (int q = 1; q <= n; q++)
		{
			level[q] = -1;
			cur[q] = adj[q].begin();
		}
		level[s] = 0;
		queue<int> qu;
		qu.push(s);
		while (!qu.empty())
		{
			int f = qu.front();
			qu.pop();
			for (auto e : adj[f])
			{
				if (level[e.to] < 0 && e.flo < e.cap)
				{
					level[e.to] = level[f]+1;
					qu.push(e.to);
				}
			}
		}
		return level[t] >= 0;
	}
	ll dfs(int v, ll flo)
	{
		if (v == t)
		{
			return flo;
		}
		for (; cur[v] != adj[v].end(); cur[v]++)
		{
			Edge &e = *cur[v];
			if (level[e.to] == level[v] + 1 && e.flo < e.cap)
			{
				ll curmin = min(flo, e.cap-e.flo);
				ll res = dfs(e.to, curmin);
				if (res > 0)
				{
					e.flo += res;
					adj[e.to][e.rev].flo -= res;
					return res;
				}
			}
		}
		return 0;
	}
	ll maxflow(int _n, int _s, int _t)
	{
		n = _n;
		s = _s;
		t = _t;
		ll tot = 0;
		while (bfs())
		{
			while (ll temp = dfs(s, LLONG_MAX))
			{
				tot += temp;
			}
		}
		return tot;
	}
};

Dinic d;

vector<int> paths[sz];
int cur = -1;
int a, b;
void dfs(int v)
{
	paths[cur].push_back(v);
	if (v == b)
	{
		return;
	}
	for (auto e : d.adj[v])
	{
		if (d.adj[e.to][e.rev].flo < 0)
		{
			d.adj[e.to][e.rev].flo = 0;
			dfs(e.to);
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int q = 0; q < m; q++)
	{
		int x,y;
		cin >> x >> y;
		d.addedge(x,y,1);
	}
	a = 1;
	b = n;
	cout << d.maxflow(n, a, b) << "\n";
	for (auto e : d.adj[a])
	{
		if (d.adj[e.to][e.rev].flo < 0)
		{
			cur++;
			paths[cur].push_back(a);
			d.adj[e.to][e.rev].flo = 0;
			dfs(e.to);
		}
	}
	for (int q = 0; q <= cur; q++)
	{
		cout << paths[q].size() << "\n";
		for (int w : paths[q])
		{
			cout << w << " ";
		}
		cout << "\n";
	}
	return 0;
}

