#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n,k;
	cin >> n >> k;
	vector<pair<ll,ll>> inter(2);
	for (int q = 0; q < 2; q++) cin >> inter[q].first >> inter[q].second;
	sort(inter.begin(), inter.end());
	bool isect = false;
	if (inter[1].first <= inter[0].second) isect = true;
	if (isect)
	{
		ll r = max(inter[0].second, inter[1].second);
		ll curint = inter[0].second-inter[0].first+inter[1].second-inter[1].first-(r-inter[0].first);
		ll tot = curint * n;
		if (tot >= k)
		{
			cout << "0\n";
			return;
		}
		ll mxtot = (r-inter[0].first) * n;
		if (mxtot >= k)
		{
			cout << k-tot << "\n";
			return;
		}
		cout << ((r-inter[0].first) - curint) * n + (k-mxtot) * 2 << "\n";
		return;
	}
	ll ans = LLONG_MAX;
	for (ll q = 1; q <= n; q++)
	{
		ll pos = q * (inter[1].first-inter[0].second);
		if ((inter[1].second-inter[0].first)*q >= k)
		{
			pos += k;
		}
		else
		{
			pos += (inter[1].second-inter[0].first) * q + (k- (inter[1].second-inter[0].first)*q) * 2;
		}
		ans = min(ans, pos);
	}
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
