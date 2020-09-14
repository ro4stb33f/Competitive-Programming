#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 998244353;

ll gcd(ll a, ll b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

ll pow(ll a, ll b)
{
	if (b == 0LL) return 1LL;
	ll x = pow(a,b/2);
	x = (x * x)%md;
	if (b % 2 == 1) x = (x * a) % md;
	return x;
}

ll inv(ll a)
{
	ll ret = pow(a,md-2LL);
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<ll> mon(n);
	for (int q = 0; q < n; q++) cin >> mon[q];
	sort(mon.begin(), mon.end());
	vector<ll> pref(n+1);
	for (int q = 1; q <= n; q++)
	{
		pref[q] = (pref[q-1] + mon[q-1])%md;
	}
	for (int q = 0; q < m; q++)
	{
		ll a,b;
		cin >> a >> b;
		auto it = lower_bound(mon.begin(), mon.end(), b);
		int idx = it - mon.begin();
		ll biggeramt = (n-idx);
		if (biggeramt < a)
		{
			cout << "0\n";
			continue;
		}
		ll higher = (((pref[n] - pref[idx])%md)+md)%md;
		ll g = gcd(biggeramt-a, biggeramt);
		ll num = (biggeramt-a)/g;
		ll den = biggeramt/g;
		ll ans = (higher * num) % md;
		ans = (ans * inv(den))%md;
		ll lower = pref[idx];
		ll g2 = gcd(biggeramt+1-a, biggeramt+1);
		ll num2 = (biggeramt+1-a)/g2;
		ll den2 = (biggeramt+1)/g2;
		lower = (lower * num2) % md;
		lower = (lower * inv(den2))%md;
		ans = (ans + lower) % md;
		cout << ans << "\n";
	}
	return 0;
}
