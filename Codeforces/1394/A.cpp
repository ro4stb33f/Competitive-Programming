#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,d,m;
	cin >> n >> d >> m;
	vector<ll> small, big;
	for (int q = 0; q < n; q++)
	{
		ll a;
		cin >> a;
		if (a > m) big.push_back(a);
		else small.push_back(a);
	}
	sort(big.rbegin(), big.rend());
	sort(small.rbegin(), small.rend());
	int s1 = small.size(), b1 = big.size();
	vector<ll> prefs(s1+1), prefb(b1+1);
	for (int q = 1; q <= s1; q++) prefs[q] = prefs[q-1]+small[q-1];
	for (int q = 1; q <= b1; q++) prefb[q] = prefb[q-1]+big[q-1];
	ll ans = 0;
	if (b1 == 0) ans = prefs[s1];
	for (int q = 1; q <= b1; q++)
	{
		if (d*q < b1-q || d*(q-1) > n-q) continue;
		if (b1-q >= d*(q-1))
		{
			ans = max(ans, prefb[q] + prefs[s1]);
		}
		else
		{
			ll remsmall = d*(q-1)-(b1-q);
			ans = max(ans, prefb[q]+prefs[s1-remsmall]);
		}
		
	}
	cout << ans << "\n";
	return 0;
}
