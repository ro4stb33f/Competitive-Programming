#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll n,m,x;
	cin >> n >> x >> m;
	ll l = x, r = x;
	for (int q = 0; q < m; q++)
	{
		ll a,b;
		cin >> a >> b;
		if (b >= l && a <= r)
		{
			l = min(l,a);
			r = max(r,b);
		}
	}
	cout << (r-l+1) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
