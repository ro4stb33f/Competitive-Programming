#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<ll> nums(n);
	for (int q = 0; q < n; q++)
	{
		cin >> nums[q];
	}
	vector<int> amts(k);
	int zeros = 0;
	for (int q = 0; q < k; q++)
	{
		cin >> amts[q];
		amts[q]--;
		if (amts[q] == 0)
		{
			zeros++;
		}
	}
	sort(nums.begin(), nums.end());
	sort(amts.rbegin(), amts.rend());
	ll tot = 0;
	for (int q = n-1; q >= n-k; q--)
	{
		tot += nums[q];
	}
	for (int q = n-1; q >= n-zeros; q--)
	{
		tot += nums[q];
	}
	for (int q = 0; q< k; q++)
	{
		nums.pop_back();
	}
	for (int q= 0; q < zeros; q++)
	{
		amts.pop_back();
	}
	int curpos = 0;
	for (int q = 0; q < k-zeros; q++)
	{
		tot += nums[curpos];
		curpos += amts[q];
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

