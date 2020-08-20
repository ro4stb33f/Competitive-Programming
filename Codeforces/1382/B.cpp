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
	int onect = 0;
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
		if (a[q] == 1)
		{
			onect++;
		}
	}
	if (n == 1)
	{
		cout << "First\n";
		return;
	}
	if (onect == n)
	{
		if (n % 2 == 0)
		{
			cout << "Second\n";
		}
		else
		{
			cout << "First\n";
		}
		return;
	}
	for (int q = 0; q < n; q++)
	{
		if (a[q] != 1)
		{
			if (q % 2 == 0)
			{
				cout << "First\n";
			}
			else
			{
				cout << "Second\n";
			}
			return;
		}
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

