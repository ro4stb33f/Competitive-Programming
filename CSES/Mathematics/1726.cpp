#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};
bool good(int x, int y)
{
	if (0 <= x && x < 8 && 0 <= y && y < 8)
	{
		return true;
	}
	return false;
}

int main()
{
	int k;
	cin >> k;
	vector<vector<int>> radj(64);
	for (int q = 0; q < 8; q++)
	{
		for (int w = 0; w < 8; w++)
		{
			for (int e = 0; e < 4; e++)
			{
				int nx = q+dx[e];
				int ny = w+dy[e];
				if (good(nx,ny))
				{
					radj[nx*8+ny].push_back(q*8+w);
				}
			}
		}
	}
	double prob[k+1][64][64];
	for (int q = 0; q < 64; q++)
	{
		for (int w = 0; w < 64; w++)
		{
			prob[0][q][w] = 0;
		}
		prob[0][q][q] = 1;
		for (int w = 1; w <= k; w++)
		{
			for (int e = 0; e < 64; e++)
			{
				prob[w][q][e] = 0;
				for (int r : radj[e])
				{
					prob[w][q][e] += prob[w-1][q][r] / (int)(radj[r].size());
				}
			}
		}
	}
	double ans = 0;
	for (int q = 0; q < 64; q++)
	{
		double expect = 1;
		for (int w=  0; w < 64; w++)
		{
			expect *= (1-prob[k][w][q]);
		}
		ans += expect;
	}
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
