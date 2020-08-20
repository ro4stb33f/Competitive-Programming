#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;
const ll mx = 1e6;
vector<ll> fact(2*mx+1);
vector<ll> invfact(2*mx+1);

ll mul(ll a, ll b)
{
	return (((a * b) % md) + md) %md;
}

ll pow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	ll ans = pow(a,b/2);
	ans = mul(ans, ans);
	if (b % 2 == 1)
	{
		ans = mul(ans, a);
	}
	return ans;
}

ll lad(ll a, ll b)
{
	return (((a+b) % md) + md)%md;
}

ll choose(ll a, ll b)
{
	return mul(mul(fact[a], invfact[b]), invfact[a-b]);
}

int main()
{
	fact[0] = 1;
	invfact[0] = 1;
	for (ll q = 1; q <= 2*mx; q++)
	{
		fact[q] = mul(fact[q-1], q);
	}
	for (ll q = 1; q <= mx; q++)
	{
		invfact[q] = pow(fact[q], md-2);
	}
	ll inv25 = pow(25LL, md-2);
	ll k;
	string s;
	cin >> k >> s;
	ll t = s.length();
	ll ss = pow(25LL, (ll)k);
	ll s26 = 1;
	ll ans = 0;
	for (ll q = 0; q <= k; q++)
	{
		ans = lad(ans, mul(choose(k+t-q-1, t-1), mul(ss, s26)));
		ss = mul(ss, inv25);
		s26 = mul(s26, 26);
	}
	cout << ans << "\n";
	return 0;
}

