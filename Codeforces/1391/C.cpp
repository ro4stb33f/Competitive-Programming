#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll md = 1e9+7;
ll pow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	ll res = pow(a,b/2);
	res = (res * res)%md;
	if (b%2 == 1)
	{
		res = (res * a)%md;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	if (n == 1)
	{
		cout << "1\n";
		return 0;
	}
	if (n == 2)
	{
		cout << "2\n";
		return 0;
	}
	ll fact = 1;
	for (ll q = 2; q <= n; q++)
	{
		fact = (fact * q)%md;
	}
	ll x = pow(2LL,n-1);
	fact = (fact - x)%md;
	fact = (fact+md)%md;
	cout << fact << "\n";
	return 0;
}

