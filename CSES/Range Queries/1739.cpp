#include <bits/stdc++.h>
using namespace std;
const int mx = 1000;
vector<vector<int>> bit(mx+1,vector<int>(mx+1));

void update(int x, int y, int inc)
{
	int y1;
	while (x <= mx)
	{
		y1 = y;
		while (y1 <= mx)
		{
			bit[x][y1] += inc;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int get(int x, int y)
{
	int tot = 0;
	int y1;
	while (x >= 1)
	{
		y1 = y;
		while (y1 >= 1)
		{
			tot += bit[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return tot;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	vector<vector<int>> forest(n+1, vector<int>(n+1));
	for (int w = 1; w <= n; w++)
	{
		string s;
		cin >> s;
		for (int e = 0; e < n; e++)
		{
			if (s[e]=='*')
			{
				update(w, e+1, 1);
				forest[w][e+1]=1;
			}
			else
			{
				forest[w][e+1]=0;
			}
		}
	}
	for (int w = 0; w < q; w++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x,y;
			cin >> x >> y;
			if (forest[x][y] == 1)
			{
				forest[x][y] = 0;
				update(x,y,-1);
			}
			else
			{
				forest[x][y] = 1;
				update(x,y,1);
			}
		}
		else
		{
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << get(x2, y2) - (get(x1-1, y2) + get(x2, y1-1) - get(x1-1, y1-1)) << "\n";
		}
	}
	return 0;
}
