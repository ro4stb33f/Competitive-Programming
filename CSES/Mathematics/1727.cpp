#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	double ans = k;
	for (int q = 1; q < k; q++)
	{
		double pow = 1;
		for (int w = 1; w <= n; w++)
		{
			pow *= 1.0*q/k;
		}
		ans -= pow;
	}
	cout << fixed << setprecision(6) << ans << "\n";
}
