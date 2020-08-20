#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
ll pow(ll x, ll y, ll mod)
{
	if (y == 0)
	{
		return 1LL;
	}
	ll res = pow(x,y/2,mod);
	res = (res * res) % mod;
	if (y % 2 == 1)
	{
		res = (res * x) % mod;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		cout << pow(a,pow(b,c,md-1), md) << "\n";
	}
	return 0;
}
