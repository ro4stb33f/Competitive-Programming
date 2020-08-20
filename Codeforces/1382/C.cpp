#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	vector<int> flips;
	for (int q = 0; q < n; q++)
	{
		int val = n-q;
		int offset = (val-1)/2;
		char c;
		int idx;
		if (val % 2 == 1)
		{
			idx = offset;
		}
		else
		{
			idx = n-1-offset;
		}
		c = b[idx];
		int cval = c-'0';
		int numf = n-1-q;
		if (numf % 2 == 1)
		{
			cval = 1-cval;
		}
		int oval = 1-cval;
		flips.push_back(q+1);
		if (oval != a[q]-'0')
		{
			flips.push_back(1);
		}
	}
	cout << flips.size() << " ";
	for (int q : flips)
	{
		cout << q << " ";
	}
	cout << "\n";
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

