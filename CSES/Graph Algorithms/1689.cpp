#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> board(8, vector<int>(8));
int step = 1;
vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
vector<int> dy = {2,1,-1,-2,-2,-1,1,2};

bool good(int a, int b)
{
	if (a >= 0 && a < 8 && b >= 0 && b < 8)
	{
		return true;
	}
	return false;
}

void solve(int a, int b)
{
	if (step == 64)
	{
		for (int q = 0; q < 8; q++)
		{
			for (int w = 0; w < 8; w++)
			{
				cout << board[q][w] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	vector<tuple<int,int,int>> possible;
	for (int q = 0; q < 8; q++)
	{
		int nx = a+dx[q];
		int ny = b+dy[q];
		if (good(nx,ny) && board[nx][ny] == 0)
		{
			int ct = 0;
			for (int w = 0; w < 8; w++)
			{
				int nxx = nx+dx[w];
				int nyy = ny+dy[w];
				if (good(nxx,nyy) && board[nxx][nyy] == 0)
				{
					ct++;
				}
			}
			if (step == 63 || ct > 0)
			{
				possible.emplace_back(ct,nx,ny);
			}
		}
	}
	sort(possible.begin(), possible.end());
	for (auto e : possible)
	{
		int p,q,r;
		tie(p,q,r)=e;
		step++;
		board[q][r] = step;
		solve(q,r);
		board[q][r] = 0;
		step--;
	}
}

int main()
{
	int x,y;
	cin >> x >> y;
	board[y-1][x-1] = 1;
	solve(y-1,x-1);
	return 0;
}
