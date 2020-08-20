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
		int x = 0;
		int a;
		while (n--)
		{
			cin >> a;
			x^=a;
		}
		cout << (x > 0 ? "first" : "second") << "\n";
	}
	return 0;
}
