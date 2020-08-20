#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >>x2 >> y2;
	x2 = x2 - x1 + 1;
	y2 = y2 - y1 + 1;
	ll mi = min(x2, y2);
	if (mi == 1)
	{
		cout << "1\n";
		return;
	}
	ll ma = max(x2, y2);
	ll res = (mi-1) * mi/2 + (mi - 1) *(ma - mi) + (mi - 2) * (mi - 1)/2;
	cout << res + 1<< "\n";
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
