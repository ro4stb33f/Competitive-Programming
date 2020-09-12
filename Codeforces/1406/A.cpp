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
	int n;
	cin >> n;
	vector<int> ct(101);
	int a[n];
	for (int q = 0; q < n; q++) cin >> a[q];
	for (int q = 0; q < n; q++) ct[a[q]]++;
	int cur = 0;
	while (ct[cur] >= 2) cur++;
	if (ct[cur] == 0)
	{
		cout << 2 * cur << "\n";
		return;
	}
	int ans = cur;
	while (ct[cur] > 0) cur++;
	cout << ans + cur << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

