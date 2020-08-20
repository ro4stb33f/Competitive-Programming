#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx =2e5;
vector<ll> sum(3*mx+5);
vector<ll> lazy(3*mx+5);
vector<bool> lazyset(3*mx+5);

void app(int k, ll inc, bool t)
{
	if (t)
	{
		lazyset[k] = t;
		lazy[k] = inc;
	}
	else
	{
		lazy[k] += inc;
	}
}

void push(int k, int l, int r)
{
	if (lazyset[k])
	{
		sum[k] = 0;
	}
	if (l != r)
	{
		//push to children
		app(2*k,lazy[k],lazyset[k]);
		app(2*k+1, lazy[k], lazyset[k]);
	}
	lazyset[k] = false;
	sum[k] += (r-l+1) * lazy[k];
	lazy[k] = 0;
}

void pull(int k)
{
	sum[k] = sum[2*k] + sum[2*k+1];
}

void update(int a, int b, int k, int l, int r, ll inc, bool t)
{
	push(k,l,r);
	if (a > r || b < l)
	{
		return;
	}
	if (a <= l && r <= b)
	{
		lazyset[k] = t;
		lazy[k] = inc;
		push(k,l,r);
		return;
	}
	int m = (l+r)/2;
	update(a,b,2*k,l,m,inc,t);
	update(a,b,2*k+1,m+1,r,inc,t);
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
		return sum[k];
	}
	int m = (l+r)/2;
	return get(a,b,2*k,l,m) + get(a,b,2*k+1,m+1,r);
}

int main()
{
	int n,q;
	cin >> n >> q;
	for (int w = 0; w < n; w++)
	{
		ll a;
		cin >> a;
		update(w,w,1,0, n-1, a,0);
	}
	for (int w = 0; w < q; w++)
	{
		ll t;
		cin >> t;
		if (t == 3)
		{
			int a,b;
			cin >> a >> b;
			cout << get(a-1,b-1,1,0,n-1) << "\n";
		}
		else if (t == 2)
		{
			int a,b;
			ll x;
			cin >> a >> b >> x;
			update(a-1,b-1,1,0,n-1,x, 1);
		}
		else
		{
			int a,b;
			ll x;
			cin >> a >> b >> x;
			update(a-1,b-1,1,0,n-1,x, 0);
		}
	}
	return 0;
}
