#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int q = 1; q <= n; q++)
	{
		cin >> a[q];
	}
	for (int q = 1; q <= n; q++)
	{
		if (a[q] > q)
		{
			cout << "-1\n";
			return 0;
		}
	}
	set<int> nums;
	for (int q = 0; q < a[n]; q++)
	{
		nums.insert(q);
	}
	vector<int> b(n+1, -1);
	for (int q = n-1; q >= 1; q--)
	{
		if (a[q] != a[q+1])
		{
			b[q+1] = a[q];
			nums.erase(a[q]);
		}
	}
	for (int q = 1; q <= n; q++)
	{
		if (b[q] == -1)
		{
			if (nums.size() == 0)
			{
				b[q] = 1e6;
			}
			else
			{
				auto it = nums.begin();
				b[q] = *it;
				nums.erase(it);
			}
		}
	}
	for (int q = 1; q <= n; q++)
	{
		cout << b[q] << " ";
	}
	return 0;
}

