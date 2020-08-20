#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<int> ct(1001);
	vector<int> ct2(1001);
	for (int q = 0; q < n; q++)
	{
		int a;
		cin >> a;
		ct[a]++;
	}
	for (int q = 0; q < m; q++)
	{
		int a;
		cin >> a;
		ct2[a]++;
	}
	for (int q = 0; q < 1001; q++)
	{
		if (ct[q] > 0 && ct2[q] > 0)
		{
			cout << "YES\n" << 1 << " " << q << "\n";
			return;
		}
	}
	cout << "NO\n";
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

