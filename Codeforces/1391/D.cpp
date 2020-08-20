#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	string grid[n];
	for (int q = 0; q < n; q++)
	{
		cin >> grid[q];
	}
	if (n == 1 || m == 1)
	{
		cout << "0\n";
		return 0;
	}
	if (n >= 4 && m >= 4)
	{
		cout << "-1\n";
		return 0;
	}
	if (n == 2)
	{
		int changes = 0;
		int changes1 = 0;
		for (int q = 0; q < m; q++)
		{
			int tot = 0;
			for (int w = 0; w < 2; w++)
			{
				if (grid[w][q] == '1')
				{
					tot++;
				}
			}
			if ((tot+q)%2 != 0)
			{
				changes++;
			}
			if ((tot+q+1)%2 != 0)
			{
				changes1++;
			}
		}
		cout << min(changes, changes1) << "\n";
		return 0;
	}
	if (m == 2)
	{
		int changes = 0;
		int changes1 = 0;
		for (int q = 0; q < n; q++)
		{
			int tot = 0;
			for (int w=  0; w < 2; w++)
			{
				if (grid[q][w] == '1')
				{
					tot++;
				}
			}
			if ((tot+q)%2 != 0)
			{
				changes++;
			}
			if ((tot+q+1)%2 != 0)
			{
				changes1++;
			}
		}
		cout << min(changes, changes1) << "\n";
		return 0;
	}
	if (n == 3)
	{
		vector<int> top(m);
		vector<int> bot(m);
		for (int q = 0; q < m; q++)
		{
			int tot = 0;
			for (int w=  0; w < 2; w++)
			{
				if (grid[w][q] == '1')
				{
					tot++;
				}
			}
			top[q] = (tot)%2;
			int tot1 = 0;
			for (int w = 1; w < 3; w++)
			{
				if (grid[w][q] == '1')
				{
					tot1++;
				}
			}
			bot[q] = (tot1)%2;
		}
		int ans = INT_MAX;
		for (int q = 0; q < 2; q++)
		{
			for (int w = 0; w < 2; w++)
			{
				int curtot = 0;
				for (int e = 0; e < m; e++)
				{
					int qcur = (q+e)%2;
					int wcur = (w+e)%2;
					if ((qcur+top[e])%2 == 1 || (wcur+bot[e])%2 == 1)
					{
						curtot++;
					}
				}
				ans = min(ans, curtot);
			}
		}
		cout << ans << "\n";
		return 0;
	}
	vector<int> top(n);
	vector<int> bot(n);
	for (int q = 0; q < n; q++)
	{
		int tot = 0;
		for (int w=  0; w < 2; w++)
		{
			if (grid[q][w] == '1')
			{
				tot++;
			}
		}
		top[q] = (tot)%2;
		int tot1 = 0;
		for (int w = 1; w < 3; w++)
		{
			if (grid[q][w] == '1')
			{
				tot1++;
			}
		}
		bot[q] = (tot1)%2;
	}
	int ans = INT_MAX;
	for (int q = 0; q < 2; q++)
	{
		for (int w = 0; w < 2; w++)
		{
			int curtot = 0;
			for (int e = 0; e < n; e++)
			{
				int qcur = (q+e)%2;
				int wcur = (w+e)%2;
				if ((qcur+top[e])%2 == 1 || (wcur+bot[e])%2 == 1)
				{
					curtot++;
				}
			}
			ans = min(ans, curtot);
		}
	}
	cout << ans << "\n";
	return 0;
}

