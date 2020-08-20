#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	string s;
	cin >> s;
	map<int,ll> earliest;
	int tot = 0;
	int sz = s.length();
	for (int q = 0; q < sz; q++)
	{
		if (s[q]=='+')
		{
			tot++;
		}
		else
		{
			tot--;
		}
		if (earliest.find(tot)==earliest.end())
		{
			earliest[tot]=q+1;
		}
	}
	ll total = 0;
	for (int q = 0; q < sz+1; q++)
	{
		if (earliest.find(-1 * q-1) == earliest.end())
		{
			total += sz;
			break;
		}
		else
		{
			total += earliest[-1 * q -1];
		}
	}
	cout << total << "\n";
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

