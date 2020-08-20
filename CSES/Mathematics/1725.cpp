#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	vector<vector<double>> prob(n+1, vector<double>(6*n+1));
	prob[0][0] = 1;
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= 6*n; w++)
		{
			for (int e = 1; w-e >= 0 && e <= 6; e++)
			{
				prob[q][w] += prob[q-1][w-e]/6;
			}
		}
	}
	double ans = 0;
	for (int q = a; q <= b; q++)
	{
		ans += prob[n][q];
	}
	printf("%.6f\n", ans);
	return 0;
}
