#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int mx = 2e5;
vector<ll> sum(3*mx+5);
vector<ll> lazyct(3*mx+5);
vector<ll> lazyoffset(3*mx+5);

void pull(int k)
{
	sum[k] = sum[2*k] + sum[2*k+1];
}

void update1(int a, int b, int k, int l, int r, ll inc)
{
	if (a > r || b < l)
	{
		return;
	}
	if (a <= l && r <= b)
	{
		sum[k] += (r-l+1) * inc;
		return;
	}
	int m = (l+r)/2;
	update1(a,b,2*k,l,m,inc);
	update1(a,b,2*k+1,m+1,r,inc);
	pull(k);
}

void app(int k, ll ctinc, ll offinc)
{
	lazyct[k] += ctinc;
	lazyoffset[k] += offinc;
}

void push(int k, int l, int r)
{
	if (lazyct[k] > 0 && l != r)
	{
		int m = (l+r)/2;
		app(2*k,lazyct[k], lazyoffset[k]);
		app(2*k+1,lazyct[k], lazyoffset[k] + lazyct[k] * (m-l+1));
	}
	ll num = (ll)((r-l+1)) * (r-l+2) / 2;
	sum[k] += (lazyct[k] * num + lazyoffset[k] * (r-l+1));
	lazyct[k] = 0;
	lazyoffset[k] = 0;
}

void update(int a, int b, int k, int l, int r)
{
	push(k,l,r);
	if (a > r || b < l)
	{
		return;
	}
	if (a <= l && r <= b)
	{
		lazyct[k] = 1;
		lazyoffset[k] = l-a;
		push(k,l,r);
		return;
	}
	int m = (l+r)/2;
	update(a,b,2*k,l,m);
	update(a,b,2*k+1,m+1,r);
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for (int w = 0; w < n; w++)
	{
		ll a;
		cin >> a;
		update1(w,w,1,0,n-1,a);
	}
	for (int w = 0; w < q; w++)
	{
		int t,a,b;
		cin >> t >> a >> b;
		if (t == 1)
		{
			update(a-1,b-1,1,0,n-1);
		}
		else
		{
			cout << get(a-1,b-1,1,0,n-1) << "\n";
		}
	}
	return 0;
}
