#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll best(ll st, ll sum)
{
	if (st+sum < 0) return (st+sum)/2;
	return (st+sum+1)/2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll a[n];
	for (int q = 0; q < n; q++) cin >> a[q];
	vector<ll> diff(n+1);
	diff[0] = a[0];
	for (int q = 1; q < n; q++) diff[q] = a[q] - a[q-1];
	ll tot = 0;
	for (int q = 1; q <= n; q++) tot += max(diff[q], 0LL);
	cout << best(diff[0], tot) << "\n";
	int qq;
	cin >> qq;
	while (qq--)
	{
		ll l,r,x;
		cin >> l >> r >> x;
		if (l > 1 && diff[l-1] > 0) tot -= diff[l-1];
		if (r < n && diff[r] > 0) tot -= diff[r];
		diff[l-1] += x;
		diff[r] -= x;
		if (l > 1 && diff[l-1] > 0) tot += diff[l-1];
		if (r < n && diff[r] > 0) tot += diff[r];
		cout << best(diff[0], tot) << "\n";
	}
	return 0;
}

