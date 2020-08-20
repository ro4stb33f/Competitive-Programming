#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int x,y;
	cin >> x >> y;
	int n = s.size();
	int st = -1;
	bool tfound = false;
	for (int q = 0; q < n; q++)
	{
		if (s[q] == 'T')
		{
			tfound = true;
			st = q;
			break;
		}
	}
	if (!tfound)
	{
		x -= n;
		if (x == 0 && y == 0)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		return 0;
	}
	else
	{
		x -= st;
	}
	vector<vector<int>> blocks(2);
	int cur = 0;
	int len = 0;
	for (int q = st; q < n; q++)
	{
		if (s[q] == 'T')
		{
			if (len > 0)
			{
				blocks[cur].push_back(len);
				len = 0;
			}
			cur^=1;
		}
		else
		{
			len++;
		}
	}
	if (s[n-1] == 'F' && tfound)
	{
		blocks[cur].push_back(len);
	}
	int xtot = 0, ytot = 0;
	int xsz = blocks[0].size();
	int ysz = blocks[1].size();
	for (int q = 0; q < xsz; q++)
	{
		xtot += -blocks[0][q];
		blocks[0][q] *= 2;
	}
	for (int q = 0; q < ysz; q++)
	{
		ytot += -blocks[1][q];
		blocks[1][q] *= 2;
	}
	int xneed = x - xtot;
	int yneed = y - ytot;
	if (xneed < 0 || yneed < 0)
	{
		cout << "No\n";
		return 0;
	}
	vector<vector<bool>> xdp (xneed+1, vector<bool>(xsz+1));
	vector<vector<bool>> ydp (yneed+1, vector<bool>(ysz+1));
	xdp[0][0] = true;
	ydp[0][0] = true;
	for (int q = 1; q <= xsz; q++)
	{
		for (int w = 0; w <= xneed; w++)
		{
			xdp[w][q] = xdp[w][q-1];
		}
		for (int w = 0; blocks[0][q-1]+w<=xneed; w++)
		{
			if (xdp[w][q-1])
			{
				xdp[w+blocks[0][q-1]][q] = true;
			}
		}
	}
	for (int q = 1; q <= ysz; q++)
	{
		for (int w = 0; w <= yneed; w++)
		{
			ydp[w][q] = ydp[w][q-1];
		}
		for (int w = 0; blocks[1][q-1]+w<=yneed; w++)
		{
			if (ydp[w][q-1])
			{
				ydp[w+blocks[1][q-1]][q] = true;
			}
		}
	}
	if (xdp[xneed][xsz] && ydp[yneed][ysz])
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	return 0;
}
