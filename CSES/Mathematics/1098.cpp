#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
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
		int nim = 0;
		int x;
		while (n--)
		{
			cin >> x;
			nim ^= (x % 4);
		}
		cout << (nim ? "first" : "second") << "\n";
	}
	return 0;
}
