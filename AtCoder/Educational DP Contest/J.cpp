#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(4);
	for (int q = 0; q < n; q++)
	{
		int a;
		cin >> a;
		v[a]++;
	}
	double dp[n+1][n+1][n+1];
	dp[0][0][0] = 0;
	for (int c = 0; c <= n; c++)
	{
		for (int b = 0; b <= n; b++)
		{
			for (int a = 0; a <= n; a++)
			{
				if (a+b+c > n)
				{
					break;
				}
				if (a+b+c == 0)
				{
					continue;
				}
				double tot = (a+b+c) * 1.0;
				dp[a][b][c] = n/tot;
				
				if (c > 0)
				{
					dp[a][b][c] += c * dp[a][b+1][c-1] / tot;
				}
				if (b > 0)
				{
					dp[a][b][c] += b * dp[a+1][b-1][c] / tot;
				}
				if (a > 0)
				{
					dp[a][b][c] += a * dp[a-1][b][c] / tot;
				}
			}
		}
	}
	printf("%.15f\n", dp[v[1]][v[2]][v[3]]);
	return 0;
}
