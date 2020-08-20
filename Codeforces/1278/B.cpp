#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	ll a, b;
	cin >> a >> b;
	ll c= abs(a-b);
	ll ct = 0;
	ll tot = 0;
	while (tot < c || (tot-c) % 2 == 1)
	{
		ct++;
		tot += ct;
	}
	cout << ct << "\n";
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

