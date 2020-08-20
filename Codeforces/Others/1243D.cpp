#include <bits/stdc++.h>
using namespace std;

struct dsu{
	vector<int> v;
	vector<int> sz;
	dsu(int n) : v(n), sz(n){
		fill(sz.begin(), sz.end(), 1);
		iota(v.begin(), v.end(), 0);
	}
	int root(int a)
	{
		return (v[a] == a ? a : v[a] = root(v[a]));
	}
	bool unite(int a, int b)
	{
		int a1 = root(a), b1 = root(b);
		if (a1 == b1) return false;
		if (sz[a1] < sz[b1]) swap(a1,b1);
		sz[a1]+=sz[b1];
		v[b1] = a1;
		return true;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dsu d(n+1);
	set<int> curcomps;
	for (int q = 1; q <= n; q++)
	{
		map<int,int> m;
		for (int a : adj[q])
		{
			if (a >= q) continue;
			int r = d.root(a);
			m[r]++;
		}
		set<int> removed;
		for (int c : curcomps)
		{
			int r = d.root(c);
			if (m[r] < d.sz[r])
			{
				d.unite(q,r);
				removed.insert(c);
			}
		}
		curcomps.insert(q);
		for (int q : removed)
		{
			curcomps.erase(q);
		}
	}
	cout << curcomps.size()-1 << "\n";
	return 0;
}
