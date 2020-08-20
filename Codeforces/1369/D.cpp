#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll md = 1e9+7;
const int mx = 2e6;

ll add(ll a, ll b)
{
	return (((a+b) % md) + md) % md;
}

ll mul(ll a, ll b)
{
	return (((a * b) % md) + md) %md;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> ans(mx+1);
	vector<bool> topcol(mx+1);
	ans[3] = 1;
	topcol[3] = true;
	for (int q = 4; q <= mx; q++)
	{
		ans[q] = add(ans[q], mul(ans[q-2], 2LL));
		ans[q] = add(ans[q], ans[q-1]);
		if (!topcol[q-1] && !topcol[q-2])
		{
			ans[q] = add(ans[q], 1LL);
			topcol[q] = true;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout <<  mul(ans[n], 4LL) << "\n";
	}
	return 0;
}

