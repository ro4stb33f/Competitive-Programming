//checked: https://cses.fi/problemset/task/1694, https://codeforces.com/contest/1360/problem/G
struct Dinic{
	int n, s, t;
	struct Edge{
		int to, rev;
		ll flo, cap;
	};
	vector<vector<Edge>> adj;
	vector<int> level;
	vector<vector<Edge>::iterator> cur;
	Dinic(int a, int b, int c): n(a), s(b), t(c)
	{
		adj.resize(n+1);
		level.resize(n+1);
		cur.resize(n+1);
	}
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
	ll maxflow()
	{
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
