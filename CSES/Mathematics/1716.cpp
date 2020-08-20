#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md =1e9+7;
const ll mx = 1e6;

ll pow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	ll res = pow(a,b/2);
	res = (res * res)%md;
	if (b % 2 == 1)
	{
		res = (res * a)%md;
	}
	return res;
}

int main()
{
	vector<ll> fact(2*mx+10);
	fact[0] = 1;
	for (ll q = 1; q < 2*mx+10; q++)
	{
		fact[q] = (q * fact[q-1]) % md;
	}
	ll a,b;
	cin >> a >> b;
	ll ans = fact[a+b-1];
	ll inv1 = pow(fact[a-1], md-2);
	ll inv2 = pow(fact[b], md-2);
	ans = (((ans * inv1) % md) * inv2)%md;
	cout << ans << "\n";
	return 0;
}
