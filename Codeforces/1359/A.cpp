#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;
	if (n/k >= m)
	{
		cout << m << "\n";
		return;
	}
	ll remaining = m - (n/k);
	if (remaining % (k-1) == 0 || k == 2)
	{
		cout << (n/k) - (remaining/(k-1)) << "\n";
		return;
	}
	else
	{
		cout << (n/k) - (remaining/(k-1)) -1 << "\n";
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
