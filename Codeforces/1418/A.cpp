#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll x,y,k;
	cin >> x >> y >> k;
	ll ans = (k + k * y - 1) / (x-1);
	if ((k + k * y - 1) % (x-1) != 0) ans++;
	ans += k;
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
