#include <bits/stdc++.h>
using namespace std;
const int sz = 1010;
typedef long long ll;

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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for (int q = 2; q <= n+1; q++)
	{
		d.addedge(1,q,1);
	}
	for (int q = 1; q <= m; q++)
	{
		d.addedge(q+n+1, n+m+2, 1);
	}
	for (int q = 0; q < k; q++)
	{
		int a,b;
		cin >> a >> b;
		a++;
		b+=n+1;
		d.addedge(a,b,1);
	}
	cout << d.maxflow(n+m+2,1,n+m+2) << "\n";
	for (int q = 2; q <= n+1; q++)
	{
		for (auto e : d.adj[q])
		{
			if (d.adj[e.to][e.rev].flo == -1)
			{
				cout << q-1 << " " << e.to-(n+1) << "\n";
			}
		}
	}
	return 0;
}

