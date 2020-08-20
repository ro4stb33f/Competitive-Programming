#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inv = 5e8+4;
const ll md = 1e9+7;
ll brute(ll x)
{
	ll tot = 0;
	for (int q = 1; q <= x; q++)
	{
		tot = (tot + q * (x/q)) % md;
	}
	return tot;
}
ll add(ll x, ll y)
{
	return ((x+y) % md + md) % md;
}
ll mul(ll x, ll y)
{
	return (((x * y) % md ) + md) % md;
}
ll fast(ll n)
{
	ll last = n;
	ll tot = n;
	ll lastseen = 1;
	for (ll q = 2; q * q <= n; q++)
	{
		ll div = n/q;
		tot = add(tot, mul(q, div));
		ll sum = mul(mul(add(last, div+1), add(last, -div)), inv);
		tot = add(tot, mul(sum, q-1));
		last = div;
		lastseen = q;
	}
	lastseen++;
	if (lastseen <= last)
	{
		ll sum = mul(mul(mul(lastseen+last, last-lastseen+1), inv), lastseen-1);
		tot = add(tot, sum);
	}
	return tot;
}
int main()
{
	ll n;
	cin >> n;
	cout << fast(n) << "\n";
	return 0;
}
