#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll md = 998244353;


ll binpow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	if (b == 1)
	{
		return (a % md);
	}
	ll res = binpow(a, b/2);
	res = (res * res) % md;
	if (b % 2 == 1)
	{
		res = (res * a) % md;
	}
	return res % md;
}

ll modinverse(ll a)
{
	return binpow(a, md-2);
}

ll choose(ll a, ll b)
{
	ll top = 1;
	for (ll q = 0; q < b; q++)
	{
		top = (((top * (a - q)) % md) + md) % md;
	}
	ll bot = 1;
	for (ll q =0; q < b; q++)
	{
		bot = (((bot * (b-q)) % md) + md) % md;
	}
	top = (top * modinverse(bot)) % md;
	return top;
}
int main()
{
	ll n,k;
	cin >> n >> k;
	if (n < k)
	{
		cout << "0\n";
		return 0;
	}
	if (k == 1)
	{
		cout << n << "\n";
		return 0;
	}
	ll tot = 0;
	for (ll q = 1; q <= n; q++)
	{
		if (n/q >= k)
		{
			tot = (tot + choose(n/q-1, k-1))%md;
		}
	}
	cout << tot << "\n";
	return 0;
}
