#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	ll n;
	cin >> n;
	set<ll> factors;
	for (ll q = 1; q * q <= n; q++)
	{
		if (n % q == 0)
		{
			factors.insert(q);
			factors.insert(n/q);
		}
	}
	auto it = factors.rbegin();
	it++;
	ll p = n / *it;
	ll ha = 1;
	ll oha = p - ha;
	cout << ha * (*it) << " " << oha * (*it)<< "\n";
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

