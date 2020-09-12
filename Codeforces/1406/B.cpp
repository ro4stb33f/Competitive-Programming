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
	vector<ll> neg, pos;
	bool zero = false;
	for (int q = 0; q < n; q++)
	{
		ll x;
		cin >> x;
		if (x < 0) neg.push_back(x);
		else if (x > 0) pos.push_back(x);
		else zero = true;
	}
	sort(neg.begin(), neg.end());
	sort(pos.rbegin(), pos.rend());
	ll ans = LLONG_MIN;
	//check if pos possible
	int a = neg.size(), b = pos.size();
	if (b >= 5) ans = max(ans, pos[0]*pos[1]*pos[2]*pos[3]*pos[4]);
	if (b >= 3 && a >= 2) ans = max(ans, pos[0]*pos[1]*pos[2]*neg[0]*neg[1]);
	if (b >= 1 && a >= 4) ans = max(ans, pos[0]*neg[0]*neg[1]*neg[2]*neg[3]);
	if (ans > 0)
	{
		cout << ans << "\n";
		return;
	}
	if (zero)
	{
		cout << "0\n";
		return;
	}
	sort(neg.rbegin(), neg.rend());
	sort(pos.begin(), pos.end());
	if (a >= 1 && b >= 4) ans = max(ans, pos[0]*pos[1]*pos[2]*pos[3]*neg[0]);
	if (a >= 3 && b >= 2) ans = max(ans, pos[0]*pos[1]*neg[0]*neg[1]*neg[2]);
	if (a >= 5) ans = max(ans, neg[0]*neg[1]*neg[2]*neg[3]*neg[4]);
	cout << ans << "\n";
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

