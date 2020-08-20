#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5;
vector<ll> lazy(3*mx+5);
vector<ll> segtree(3*mx+5);

void push(int k, int l, int r)
{
	if (l != r)
	{
		lazy[2*k] += lazy[k];
		lazy[2*k+1] += lazy[k];
	}
	segtree[k] += lazy[k];
	lazy[k] = 0;
}

void pull(int k)
{
	segtree[k] = max(segtree[2*k], segtree[2*k+1]);
}

void update(int a, int b, int k, int x, int y, ll inc)
{
	push(k,x,y);
	if (x > b || y < a)
	{
		return;
	}
	if (a <= x && y <= b)
	{
		lazy[k]=inc;
		push(k,x,y);
		return;
	}
	int m = (x+y)/2;
	update(a,b,2*k,x,m,inc);
	update(a,b,2*k+1,m+1,y,inc);
	pull(k);
}

ll get(int a, int b, int k, int x, int y)
{
	push(k,x,y);
	if (x > b || y < a)
	{
		return LLONG_MIN;
	}
	if (a <= x && y <= b)
	{
		return segtree[k];
	}
	int m = (x+y)/2;
	return max(get(a,b,2*k, x, m), get(a,b,2*k+1,m+1,y));
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<ll> inc[n+1];
	vector<pair<ll, ll>> rem[n+1];
	for (int q = 0; q < m; q++)
	{
		ll l,r,a;
		cin >> l >> r >> a;
		inc[l].push_back(a);
		rem[r].push_back({l,a});
	}
	ll ans = 0;
	for (int q = 1; q <= n; q++)
	{
		for (ll w : inc[q])
		{
			update(0,q-1,1,0,n,w);
		}
		ll best = get(0,q-1,1,0,n);
		update(q,q,1,0,n,best);
		for (pair<ll,ll> w : rem[q])
		{ 
			update(0,w.first-1,1,0,n,-1 * w.second);
		}
		ans = max(ans, best);
	}
	cout << ans << "\n";
	return 0;
}
