#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int a[k];
	while (k--)
	{
		cin >> a[k];
	}
	vector<int> w(n+1);
	for (int q = 1; q <= n; q++)
	{
		for (int x : a)
		{
			if (q-x >= 0 && !w[q-x])
			{
				w[q]= 1;
			}
		}
		cout << (w[q] ? 'W' : 'L');
	}
}
