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
	ll housetot= 0;
	vector<ll> houses(n);
	for (int q = 0; q < n; q++)
	{
		cin >> houses[q];
		housetot+=houses[q];
	}
	vector<ll> power(n);
	ll powtot = 0;
	vector<pair<ll,ll>> range(n);
	for (int q = 0; q < n; q++)
	{
		cin >> power[q];
		powtot += power[q];
		int next = (q+n+1) % n;
		range[next] = {0,power[q]};
	}
	if (powtot < housetot)
	{
		cout << "NO\n";
		return;
	}
	vector<pair<ll,ll>> offset(n);
	for (int q = 0; q < n; q++)
	{
		int prev = (q+n-1) % n;
		int next = (q+n+1) % n;
		offset[q].first = (houses[q]-power[q]);
		offset[q].second = (power[prev]-houses[prev]);
	}
	for (int w = 0; w <= 2*n; w++)
	{
		int q = w%n;
		int prev = (q+n-1) % n;
		int next = (q+n+1) % n;
		if (range[q].second < range[next].first + offset[q].first)
		{
			cout << "NO\n";
			return;
		}
		if (range[q].first > range[prev].second + offset[q].second)
		{
			cout << "NO\n";
			return;
		}
		range[q].first = max(range[q].first, range[next].first+offset[q].first);
		range[q].second = min(range[q].second, range[prev].second + offset[q].second);
	}
	cout << "YES\n";
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

