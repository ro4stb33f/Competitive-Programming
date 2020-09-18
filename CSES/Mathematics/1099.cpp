#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int m = 0;
		for (int q = 0; q < n; q++)
		{
			int c;
			cin >> c;
			if (q % 2) m^=c;
		}
		cout << (m == 0 ? "second\n" : "first\n");
	}
	return 0;
}
