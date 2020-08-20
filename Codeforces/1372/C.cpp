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
	vector<int> a(n+1);
	for (int q= 1; q <= n; q++)
	{
		cin >> a[q];
	}
	int lidx = -1;
	for (int q = 1; q <= n; q++)
	{
		if (a[q] != q)
		{
			lidx = q;
			break;
		}
	}
	int ridx = -1;
	for (int q = n; q>= 1; q--)
	{
		if (a[q] != q)
		{
			ridx = q;
			break;
		}
	}
	if (lidx == -1 && ridx == -1)
	{
		cout << "0\n";
		return;
	}
	bool zerofound = false;
	for (int q = lidx; q <= ridx; q++)
	{
		if (a[q] == q)
		{
			zerofound = true;
			break;
		}
	}
	if (!zerofound)
	{
		cout << "1\n";
		return;
	}
	else
	{
		cout << "2\n";
		return;
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

