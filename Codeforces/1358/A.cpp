#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve()
{
	ll m,n;
	cin >> m >> n;
	if (m % 2 ==1 && n % 2 == 1)
	{
		cout << (m * n / 2 + 1) << "\n";
	}
	else
	{
		cout << ( m * n / 2) << "\n";
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
