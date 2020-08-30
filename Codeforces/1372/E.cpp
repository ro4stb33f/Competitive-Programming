#include <bits/stdc++.h>
using namespace std;
const int mx = 100;
int amt[mx+1][mx+1];
int amtin[mx+1][mx+1][mx+1];
int prefamt[mx+1][mx+1];
int suffamt[mx+1][mx+1];
int dp[mx+1][mx+1];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int q = 0; q < n; q++)
	{
		int x;
		cin >> x;
		for (int w = 0; w < x; w++)
		{
			int l,r;
			cin >> l >> r;
			amt[l][r]++;
		}
	}
	for (int l = 1; l <= m; l++)
	{
		for (int r = l; r <= m; r++) prefamt[l][r] = amt[l][r] + prefamt[l][r-1];
		for (int r = l; r >= 1; r--) suffamt[r][l] = amt[r][l] + suffamt[r+1][l];
	}
	for (int e = 1; e <= m; e++)
	{
		for (int l = 1; l+e-1 <= m; l++)
		{
			int r = l+e-1;
			for (int q = l; q <= r; q++)
			{
			   	amtin[l][r][q] = prefamt[l][r]-prefamt[l][q-1] + suffamt[l][r] - suffamt[q+1][r] - amt[l][r];
				if (l < q && q < r) amtin[l][r][q] += amtin[l+1][r-1][q];
			}
		}
	}
	for (int e = 1; e <= m; e++)
	{
		for (int l = 1; l+e-1 <= m; l++)
		{
			int r = l+e-1;
			if (e == 1)
			{
				dp[l][r] = amtin[l][l][l] * amtin[l][l][l];
				continue;
			}
			for (int q = l; q <= r; q++)
			{
				int tot = amtin[l][r][q] * amtin[l][r][q];
				if (q > l) tot += dp[l][q-1];
				if (q < r) tot += dp[q+1][r];
				dp[l][r] = max(dp[l][r], tot);
			}
		}
	}
	cout << dp[1][m] << "\n";
	return 0;
}
