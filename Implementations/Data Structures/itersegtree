//checked: https://cses.fi/problemset/task/1649
struct segtree{
	int n;
	vector<ll> v;
	segtree(int x): n(x)
	{
		v.resize(2*n+5);
	}
	void update(int i, ll x)
	{
		i+=n;
		v[i] = x;
		for (i /= 2; i >= 1; i /= 2)
			v[i] = min(v[2*i], v[2*i+1]);
	}
	ll get(ll l, ll r)
	{
		ll ans = LLONG_MAX;
		for (l+=n, r+=n; l <= r; l/=2, r/=2)
		{
			if (l%2)
				ans = min(ans, v[l++]);
			if (r%2==0)
				ans = min(ans, v[r--]);
		}
		return ans;
	}
};
