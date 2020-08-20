#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll a, b;
	cin >> a >> b;
	if (a == b)
	{
		cout << "0\n";
		return;
	}
	ll ma = max(a,b);
	ll mi = min(a,b);
	if (ma % mi != 0)
	{
		cout << "-1\n";
		return;
	}
	ll div = ma / mi;
	ll ctr = 0;
	while (div > 1)
	{
		if (div % 2 == 1)
		{
			cout << "-1\n";
			return;
		}
		if (div % 8 == 0)
		{
			div /= 8;
		}
		else if (div % 4 == 0)
		{
			div /= 4;
		}
		else
		{
			div /= 2;
		}
		ctr++;
	}
	cout << ctr << "\n";
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
