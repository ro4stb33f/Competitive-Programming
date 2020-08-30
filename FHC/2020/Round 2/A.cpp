#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> s(n);
	for (int q = 0; q < k; q++) cin >> s[q];
	ll as,bs,cs,ds;
	cin >> as >> bs >> cs >> ds;
	vector<ll> x(n);
	for (int q = 0; q < k; q++) cin >> x[q];
	ll ax,bx,cx,dx;
	cin >> ax >> bx >> cx >> dx;
	vector<ll> y(n);
	for (int q = 0; q < k; q++) cin >> y[q];
	ll ay,by,cy,dy;
	cin >> ay >> by >> cy >> dy;
	for (int q = k; q < n; q++)
	{
		s[q] = (((as * s[q-2]) % ds) + ((bs * s[q-1]) % ds) + cs) % ds;
		x[q] = (((ax * x[q-2]) % dx) + ((bx * x[q-1]) % dx) + cx) % dx;
		y[q] = (((ay * y[q-2]) % dy) + ((by * y[q-1]) % dy) + cy) % dy;
	}
	ll tots = 0, totx = 0, toty = 0;
	for (int q = 0; q < n; q++)
	{
		tots += s[q];
		totx += x[q];
		toty += x[q]+y[q];
	}
	if (tots < totx || tots > toty)
	{
		cout << "-1\n";
		return;
	}
	ll subbed = 0;
	ll added = 0;
	for (int q = 0; q < n; q++)
	{
		if (s[q] < x[q]) added += x[q]-s[q];
		if (s[q] > x[q]+y[q]) subbed += s[q]-x[q]-y[q];
	}
	ll ans = max(subbed, added);
	cout << ans << "\n";
}

int main()
{
	freopen("capastaty_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ": ";
		solve();
	}
	return 0;
}
