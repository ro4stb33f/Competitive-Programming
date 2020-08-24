#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 3e5;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
LineContainer st[4*mx+20];

void update(int i, int k, int l, int r, ll slope, ll off)
{
	if (i < l || i > r) return;
	st[k].add(slope,off);
	if (l == r) return;
	int m = (l+r)/2;
	update(i,2*k,l,m,slope,off);
	update(i,2*k+1,m+1,r,slope,off);
}

ll get(int a, int b, int k, int l, int r, ll x)
{
	if (r < a || l > b) return LLONG_MAX;
	if (a <= l && r <= b) return (st[k].size() == 0 ? LLONG_MAX : -st[k].query(x));
	int m = (l+r)/2;
	return min(get(a,b,2*k,l,m,x), get(a,b,2*k+1,m+1,r,x));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll dp[n+1], p[n+1], a[n+1], h[n+1];
	for (int q = 1; q <= n; q++) cin >> p[q];
	for (int q = 1; q <= n; q++) cin >> a[q];
	for (int q = 1; q <= n; q++) cin >> h[q];
	dp[n] = a[n];
	update(n,1,0,n,2LL * h[n], -h[n]*h[n]-dp[n]);
	for (int q = n-1; q >= 1; q--)
	{
		ll x = get(p[q]+1,n,1,0,n,h[q]);
		dp[q] = x + a[q] + h[q] * h[q];
		update(p[q],1,0,n,2LL * h[q], -h[q]*h[q]-dp[q]);
	}
	cout << dp[1] << "\n";
	return 0;
}
