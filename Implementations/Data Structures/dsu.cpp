//checked: https://codeforces.com/contest/1243/problem/D
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
