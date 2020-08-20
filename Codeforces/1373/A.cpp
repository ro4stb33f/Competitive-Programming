#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	ll a,b,c;
	cin >> a >> b >> c;
	if (a * b <= c)
	{
		cout << "1 -1\n";
		return;
	}
	if (a > c)
	{
		cout << "-1 " << b << "\n";
	}
	else if (a ==c )
	{
		cout << "-1 " << b << "\n";
	}
	else
	{
		cout << "1 " << b << "\n";
	}
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

