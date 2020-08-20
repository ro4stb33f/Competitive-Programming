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
	vector<int> a(n);
	ll cur = 0;
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
		cur = cur^a[q];
	}
	if (cur == 0)
	{
		cout << "DRAW\n";
		return;
	}
	int largest = -1;
	for (int q = 0; q < 31; q++)
	{
		if (((1LL << q)&cur) > 0)
		{
			largest = q;
		}
	}
	int ct = 0;
	for (int q = 0; q < n; q++)
	{
		if (((1LL << largest)&a[q]) > 0)
		{
			ct++;
		}
	}
	int ha = ct - ct/2;
	if (ha % 2 == 0)
	{
		if (n % 2 == 0)
		{
			cout << "WIN\n";
		}
		else
		{
			cout << "LOSE\n";
		}
	}
	else
	{
		cout << "WIN\n";
	}
	return;
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

