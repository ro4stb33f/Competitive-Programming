#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int mx = 1e6;
ll pow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	ll res = pow(a,b/2);
	res = (res * res) % md;
	if (b % 2 == 1)
	{
		res = (res * a) % md;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> fact(mx+1);
	fact[0]=1;
	for (ll q = 1; q <= mx; q++)
	{
		fact[q] = (fact[q-1] * q) % md;
	}
	cin >> t;
	while (t--)
	{
		ll a,b;
		cin >> a >> b;
		ll ans = fact[a];
		ll inv1 = pow(fact[b], md-2);
		ll inv2 = pow(fact[a-b], md-2);
		ans = (((ans * inv1) % md) * inv2) % md;
		cout << ans << "\n";
	}
	return 0;
}
