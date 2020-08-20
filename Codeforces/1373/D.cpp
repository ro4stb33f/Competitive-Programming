#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	ll n;
	cin >> n;
	vector<pair<ll,ll>> sums;
	sums.emplace_back(0,0);
	vector<ll> nums;
	for (int q = 1; q <= n; q++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
		sums.emplace_back(sums[q-1].first, sums[q-1].second);
		if (q % 2 == 1)
		{
			sums[q].first += a;
		}
		else
		{
			sums[q].second += a;
		}
	}
	vector<ll> dif(n+1);
	for (int q = 0; q <= n; q++)
	{
		dif[q] = sums[q].second-sums[q].first;
	}
	set<ll> odd;
	set<ll> even;
	even.insert(dif[0]);
	odd.insert(dif[1]);
	ll best = 0;
	for (int q =2; q <= n; q++)
	{
		if (q % 2 == 0)
		{
			ll diff = dif[q] - *even.begin();
			best = max(best, diff);
			even.insert(dif[q]);
		}
		else
		{
			ll diff = dif[q] - *odd.begin();
			best = max(best, diff);
			odd.insert(dif[q]);
		}
	}
	ll tot = 0;
	for (int q = 0; q < n; q +=2)
	{
		tot += nums[q];
	}
	cout << (tot + best) << "\n";
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

