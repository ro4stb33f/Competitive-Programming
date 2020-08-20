//checked: https://cses.fi/problemset/task/1735
//lazy segment tree with add and set on range
struct lazyseg{
	struct node{
		ll sum;
		ll lazyadd;
		bool lazyset;
	};
	vector<node> v;
	lazyseg(int n)
	{
		v.resize(n);
	}
	void app(int k, ll inc, bool t)
	{
		if (t)
		{
			v[k].lazyset = t;
			v[k].lazyadd = inc;
		}
		else
			v[k].lazyadd += inc;
	}
	void push(int k, int l, int r)
	{
		if (v[k].lazyset) v[k].sum = 0;
		if (l != r)
		{
			app(2*k,v[k].lazyadd,v[k].lazyset);
			app(2*k+1,v[k].lazyadd,v[k].lazyset);
		}
		v[k].sum += (r-l+1) * v[k].lazyadd;
		v[k].lazyadd = 0;
		v[k].lazyset = false;
	}
	void pull(int k)
	{
		v[k].sum = v[2*k].sum + v[2*k+1].sum;
	}
	void update(int a, int b, int k, int l, int r, ll inc, bool t)
	{
		push(k,l,r);
		if (a > r || b < l) return;
		if (a <= l && r <= b)
		{
			v[k].lazyset = t;
			v[k].lazyadd = inc;
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
		if (a > r || b < l) return 0LL;
		if (a <= l && r <= b) return v[k].sum;
		int m = (l+r)/2;
		return get(a,b,2*k,l,m) + get(a,b,2*k+1,m+1,r);
	}
};
