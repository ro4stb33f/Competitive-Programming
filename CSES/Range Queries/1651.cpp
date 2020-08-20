#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll get(vector<ll>& bit, int i)
{
	ll res = 0;
	while (i >= 1)
	{
		res += bit[i];
		i -=(i & -i);
	}
	return res;
}
void update(vector<ll>&bit, int a, ll inc)
{
	while (a <= n)
	{
		bit[a]+=inc;
		a += (a & -a);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	vector<ll> bit(n+2);
	ll b;
	cin >> b;
	update(bit, 1, b);
	ll prev = b;
	for (int w = 2; w <= n; w++)
	{
		ll a;
		cin >> a;
		update(bit, w, a-prev);
		prev = a;
	}
	for (int w = 0; w < q; w++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			ll a,b,u;
			cin >> a >> b >> u;
			update(bit, a, u);
			update(bit, b+1, -u);
		}
		else
		{
			int k;
			cin >> k;
			cout << get(bit, k) << "\n"; 
		}
	}
	return 0;
}
