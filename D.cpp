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
	vector<int> ct(20);
	for (int q = 0; q < n; q++)
	{
		ll a;
		cin >> a;
		for (ll q = 0; q < 20; q++)
		{
			if ((a&(1LL<<q)) > 0)
			{
				ct[q]++;
			}
		}
	}
	vector<ll> ans;
	for (int q = 0; q < n; q++)
	{
		ll num = 0;
		for (int w = 0; w < 20; w++)
		{
			if (ct[w] > 0)
			{
				ct[w]--;
				num += ((1LL) << w);
			}
		}
		ans.push_back(num);
	}
	ll tot = 0;
	for (ll q : ans)
	{
		tot+=(q * q);
	}
	cout << tot << "\n";
	return 0;
}

