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
	for (int q = 1; q <= n; q++)
	{
		cin >> a[q];
	}
	int k = 0;
	vector<int> extremes;
   	extremes.push_back(a[1]);	
	for (int q = 2; q <= n-1; q++)
	{
		if (a[q] > a[q-1] && a[q] > a[q+1])
		{
			extremes.push_back(a[q]);
		}
		else if (a[q] < a[q-1] && a[q] < a[q+1])
		{
			extremes.push_back(a[q]);
		}
	}
	extremes.push_back(a[n]);
	cout << extremes.size() << "\n";
	for (int q = 0; q < extremes.size(); q++)
	{
		cout << extremes[q] << " ";
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

