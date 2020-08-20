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
	vector<int> jam(2*n);
	for (int q = 0; q < 2*n; q++)
	{
		int a;
		cin >> a;
		if (a == 2)
		{
			jam[q] = 1;
		}
		else
		{
			jam[q] = -1;
		}
	}
	int tot = 0;
	for (int q = 0; q < 2*n; q++)
	{
		tot += jam[q];
	}
	if (tot == 0)
	{
		cout << "0\n";
		return;
	}
	map<int,int> earliest;
	earliest[0] = n-1;
	int cur = 0;
	for (int q = n; q < 2*n; q++)
	{
		cur += jam[q];
		if (earliest.find(cur) == earliest.end())
		{
			earliest[cur] = q;
		}
	}
	int cursum = 0;
	int curbest = 2*n;
	if (earliest.find(tot) != earliest.end())
	{
		curbest = earliest[tot]-n+1;
	}
	for (int q = n-1; q >= 0; q--)
	{
		cursum += jam[q];
		if (earliest.find(tot-cursum) != earliest.end())
		{
			int e = earliest[tot-cursum];
			int jameat = n-1-q+1 + e-n+1;
			curbest = min(curbest, jameat);
		}
	}
	cout << curbest << "\n";
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

