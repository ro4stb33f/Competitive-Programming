//checked https://cses.fi/problemset/task/1647/
template<class T, int n, int lg> struct SparseTable{
	T st[lg][n];
	T comb(T x, T y)
	{
		return min(x,y);
	}
	void build(vector<T>& v, T inf)
	{
		for (int q = 0; q < lg; q++)
		{
			for (int w = 0; w < n; w++)
			{
				st[q][w] = inf;
				if (w + (1<<q)-1 < n) st[q][w] = (q == 0 ? v[w] : comb(st[q-1][w], st[q-1][w+(1<<(q-1))]));
			}
		}
	}
	T query(int l, int r)
	{
		int x = (l == r ? 0 : 31-__builtin_clz(r-l));
		return comb(st[x][l], st[x][r-(1<<x)+1]);
	}
};
