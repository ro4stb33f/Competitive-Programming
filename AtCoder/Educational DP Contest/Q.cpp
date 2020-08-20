#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 400005;
vector<ll> segtree(mx);
int n;
ll get(int a, int b)
{
	ll ret = -1;
	a += (n+1);
	b += (n+1);
	while (a <= b)
	{
		if (a % 2 == 1)
		{
			ret = max(ret, segtree[a++]);
		}
		if (b % 2 == 0)
		{
			ret = max(ret, segtree[b--]);
		}
		a /= 2;
		b /= 2;
	}
	return ret;
}

void update(int i, ll val)
{
	i += (n+1);
	segtree[i] = val;
	for (int q = i/2; q >= 1; q /=2)
	{
		segtree[q] = max(segtree[2 * q], segtree[2 * q + 1]);
	}
}

int main()
{
	cin >> n;
	vector<ll> h(n);
	vector<ll> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> h[q];
	}
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	for (int q = 0; q < n; q++)
	{
		ll x = get(0, h[q]-1);
		update(h[q], x + a[q]);
	}
	cout << get(0, n) << "\n";
	return 0;
}
