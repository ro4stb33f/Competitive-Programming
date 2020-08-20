#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5;
vector<int> adj[mx+1];
vector<pair<int,int>> order(mx+1);
vector<ll> st(3*mx+5);
vector<ll> lazy(3*mx+5);
int t = -1;

void app(int k, ll inc)
{
	lazy[k] += inc;
}

void push(int k, int l, int r)
{
	if (l != r)
	{
		lazy[2*k] += lazy[k];
		lazy[2*k+1] += lazy[k];
	}
	st[k] += (r-l+1) * lazy[k];
	lazy[k] = 0;
}

void pull(int k)
{
	st[k] = st[2*k]+st[2*k+1];
}

void update(int a, int b, int k, int l, int r, ll inc)
{
	push(k,l,r);
	if (a > r || b < l)
	{
		return;
	}
	if (a <= l && r <= b)
	{
		lazy[k] = inc;
		push(k,l,r);
		return;
	}
	int m = (l+r)/2;
	update(a,b,2*k,l,m,inc);
	update(a,b,2*k+1,m+1,r,inc);
	pull(k);
}

ll get(int a, int b, int k, int l, int r)
{
	push(k,l,r);
	if (a > r || b < l)
	{
		return 0;
	}
	if (a <= l && r <= b)
	{
		return st[k];
	}
	int m = (l+r)/2;
	return get(a,b,2*k,l,m) + get(a,b,2*k+1,m+1,r);
}

void dfs(int v, int p)
{
	t++;
	order[v].first = t;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a,v);
		}
	}
	order[v].second = t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	vector<ll> vals(n+1);
	for (int w = 1; w <= n; w++)
	{
		cin >> vals[w];
	}
	for (int w = 0; w < n-1; w++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	for (int w = 1; w <= n; w++)
	{
		update(order[w].first, order[w].second, 1,0,n-1, vals[w]);
	}
	for (int w = 0; w < q; w++)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			int a;
			ll b;
			cin >> a >> b;
			update(order[a].first, order[a].second, 1,0,n-1, b-vals[a]);
			vals[a] = b;
		}
		else
		{
			int a;
			cin >> a;
			cout << get(order[a].first, order[a].first, 1,0,n-1) << "\n";
		}
	}
	return 0;
}
