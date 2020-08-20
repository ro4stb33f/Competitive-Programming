//checked: https://cses.fi/problemset/task/1739
struct bit2d{
	int n;
	vector<vector<int>> bit;
	bit2d(int x) : n(x)
	{
		bit.resize(n+1, vector<int>(n+1));
	}
	void update(int x, int y, int inc)
	{
		for (;x <= n; x += (x&-x))
			for (int y1 = y; y1 <= n; y1 += (y1 & -y1))
				bit[x][y1] += inc;
	}
	int get(int x, int y)
	{
		int tot = 0;
		for (; x >= 1; x -= (x & -x))
			for (int y1 = y; y1 >= 1; y1 -= (y1 & -y1))
				tot += bit[x][y1];
		return tot;
	}
};
