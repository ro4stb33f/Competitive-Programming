#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	double ans = 0;
	for (int q = 0; q < n; q++)
	{
		for (int w = 1; w <= a[q]; w++)
		{
			double tot = 0;
			for (int e = q+1; e < n; e++)
			{
				tot += 1.0*min(w-1, a[e])/a[e];
			}
			ans += tot/a[q];
		}
	}
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
