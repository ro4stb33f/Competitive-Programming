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
	int sz = s.length();
	int one = 0, zero = 0;
	for (int q = 0; q < sz; q++)
	{
		if (s[q] == '0')
		{
			zero++;
		}
		else
		{
			one++;
		}
	}
	int mi = min(one,zero);
	if (mi % 2 == 1)
	{
		cout << "DA\n";
	}
	else
	{
		cout << "NET\n";
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

