#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e6;
const ll inf = 1e17;
vector<ll> st(2*mx+20);
int n;

void reset()
{
	for (int q = 2*n+4; q >= 1; q--)
	{
		st[q] = inf;
	}
}

void update(int i, ll val)
{
	i += n;
	st[i] = val;
	i /= 2;
	while (i >= 1)
	{
		st[i] = min(st[2*i], st[2*i+1]);
		i /= 2;
	}
}

ll get(int a, int b)
{
	a += n;
	b += n;
	ll x = inf;
	while (a <= b)
	{
		if (a % 2 == 1)
		{
			x = min(x, st[a]);
			a++;
		}
		if (b % 2 == 0)
		{
			x = min(x, st[b]);
			b--;
		}
		a/=2;
		b/=2;
	}
	return x;
}

ll getsingle(int a)
{
	return st[a+n];
}

void solve()
{
	int m,a,b;
	cin >> n >> m >> a >> b;
	reset();
	vector<vector<int>> adj(n+1);
	vector<ll> val(n+1);
	for (int q = 1; q <= n; q++)
	{
		int p;
		cin >> p >> val[q];
		if (p != 0)
		{
			adj[q].push_back(p);
			adj[p].push_back(q);
		}
	}
	vector<int> par(n+1,-1);
	vector<int> depth(n+1);
	par[a] = 0;
	queue<int> bfs;
	bfs.push(a);
	while (!bfs.empty())
	{
		int t = bfs.front();
		bfs.pop();
		for (int x : adj[t])
		{
			if (x == par[t])
			{
				continue;
			}
			depth[x] = depth[t]+1;
			par[x] = t;
			bfs.push(x);
		}
	}
	vector<int> path;
	int cur = b;
	while (cur != a)
	{
		path.push_back(cur);
		cur = par[cur];
	}
	path.push_back(a);
	reverse(path.begin(), path.end());
	int sz = path.size();
	if (sz - 1 <= m)
	{
		cout << "0\n";
		return;
	}
	update(0,0);
	for (int q = 1; q < sz; q++)
	{
		vector<ll> mincostd;
		int mxdepth = m/2;
		if (q <= m)
		{
			mxdepth = min(mxdepth, q-1);
		}
		int lbound1 = max(0, q-m);
		int rbound1 = q-1;
		if (val[path[q]] != 0 || q == sz-1)
		{
			ll pos = get(lbound1, rbound1);
			if (pos != inf)
			{
				update(q, pos+val[path[q]]);
			}
		}
		if (q == sz-1)
		{
			break;
		}
		queue<int> bf;
		bf.push(path[q]);
		int curdepth = 0;
		int nextpos = path[q+1];
		while (curdepth < mxdepth && !bf.empty())
		{
			mincostd.push_back(inf);
			int sz1 = bf.size();
			for (int w = 0; w < sz1; w++)
			{
				int t = bf.front();
				bf.pop();
				for (int ad : adj[t])
				{
					if (ad == par[t] || ad == nextpos)
					{
						continue;
					}
					if (val[ad] != 0)
					{
						mincostd[curdepth] = min(mincostd[curdepth], val[ad]);
					}
					bf.push(ad);
				}
			}
			curdepth++;
		}
		int sz2 = mincostd.size();
		for (int w = 0; w < sz2; w++)
		{
			if (mincostd[w] == inf)
			{
				continue;
			}
			int rbound = q-(w+1)-1;
			int lbound = max(0, q-(m-(w+1)));
			if (rbound >= 0 && lbound <= rbound)
			{
				ll pval = get(lbound, rbound);
				if (pval == inf)
				{
					continue;
				}
				pval += mincostd[w];
				mincostd[w] = pval;
			}
			else
			{
				mincostd[w] = inf;
			}
		}
		for (int w = 0; w < sz2; w++)
		{
			if (mincostd[w] == inf)
			{
				continue;
			}
			int rbound = q-(w+1);
			if (rbound >= 0 && mincostd[w] < getsingle(rbound))
			{
				update(q-(w+1), mincostd[w]);
			}
		}
		
	}
	ll potential = getsingle(sz-1);
	if (potential == inf)
	{
		cout << "-1\n";
	}
	else
	{
		cout << (potential - val[path[sz-1]]) << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("running_on_fumes_chapter_2_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ": ";
		solve();
	}
	return 0;
}
