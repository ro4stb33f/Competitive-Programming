#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n,m;
	cin >> n >> m;
	string grid[n];
	for (int q = 0; q < n; q++)
	{
		cin >> grid[q];
	}
	if (n == 1)
	{
		if (m == 1)
		{
			cout << "0\n";
			return;
		}
		int tot = 0;
		for (int q = 0; q < m; q++)
		{
			if (grid[0][q] == 'D')
			{
				tot++;
			}
		}
		cout << tot << "\n";
		return;
	}
	if (m == 1)
	{
		int tot = 0;
		for (int q=  0; q < n; q++)
		{
			if (grid[q][0] == 'R')
			{
				tot++;
			}
		}
		cout << tot << "\n";
		return;
	}
	int tot = 0;
	for (int q = 0; q < m; q++)
	{
		if (grid[n-1][q] == 'D')
		{
			tot++;
		}
	}
	for (int q = 0; q < n; q++)
	{
		if (grid[q][m-1] == 'R')
		{
			tot++;
		}
	}
	cout << tot << "\n";
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

