#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> ct(mx+1);
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		for (int q = 1; q * q <= x; q++)
		{
			if (x % q == 0)
			{
				ct[q]++;
				if (x/q != q)
				{
					ct[x/q]++;
				}
			}
		}
	}
	for (int q = mx; q >= 0; q--)
	{
		if (ct[q] > 1)
		{
			cout << q << "\n";
			break;
		}
	}
	return 0;
}
