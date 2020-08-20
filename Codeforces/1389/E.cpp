#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b%a, a);
}

void solve()
{
	ll m,d,w;
	cin >> m >> d >> w;
	ll x = gcd(d-1, w);
	ll md = w/x;
	ll most = min(m,d);
	ll rem = most % md;
	ll div = most / md;
	ll tot = (div+1) * div/2 * rem + div * (div-1)/2 * (md-rem);
	cout << tot << "\n";
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

