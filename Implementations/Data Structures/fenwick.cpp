//checked: https://cses.fi/problemset/task/1648
struct bit{
	int n;
	vector<ll> v;
	bit(int x) : n(x)
	{
		v.resize(n+1);
	}
	void update(int i, ll inc)
	{
		for (;i <= n; i += (i & -i))
			v[i]+=inc;
	}
	ll get(int i)
	{
		ll tot = 0;
		for (;i >= 1; i -= (i & -i))
			tot+=v[i];
		return tot;
	}
};
