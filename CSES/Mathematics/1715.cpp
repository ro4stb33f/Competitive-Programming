#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1e6;
const ll md = 1e9+7;
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
	vector<ll> fact(mx+1, 1);
	for (ll q = 1; q <= mx; q++)
	{
		fact[q] = (q * fact[q-1]) % md;
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<ll> ct(26);
	int n = s.size();
	for (int q = 0; q < n; q++)
	{
		ct[s[q]-'a']++;
	}
	ll ans = fact[n];
	for (int q = 0; q < 26; q++)
	{
		ll inv = pow(fact[ct[q]], md-2);
		ans = (ans * inv) % md;
	}
	cout << ans << "\n";
	return 0;
}
