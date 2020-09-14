#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bit{
	int n;
	vector<ll> v;
	bit(int x) : n(x)
	{
		v.resize(n+1);
	}
	void update(int i, ll inc)
	{
		for (;i <= n; i += (i & -i)) v[i]+=inc;
	}
	ll get(int i)
	{
		ll tot = 0;
		for (;i >= 1; i -= (i & -i)) tot+=v[i];
		return tot;
	}
	ll upper_bound(ll x)
	{
		ll i = 0, tot = 0;
		for (ll q = 18; q >= 0; q--)
		{
			if (i+(1<<q) <= n && tot+v[i+(1<<q)] <= x)
			{
				i+=(1<<q);
				tot+=v[i];
			}
		}
		return i+1;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,l,r;
	cin >> n >> m >> l >> r;
	ll mn = max(m,n);
	vector<vector<ll>> divisors(2*mn+20);
	for (ll q = 1; q <= 2*mn; q++)
	{
		for (ll w = q; w <= 2*mn; w+=q) divisors[w].push_back(q);
	}
	for (ll q = 1; q <= n/2; q++)
	{
		ll lo = (l+q-1)/q, hi = min(r/q,m);
		if (lo > hi)
		{
			cout << "-1\n";
			continue;
		}
		if (hi-lo>=1)
		{
			ll y = lo+(lo%2);
			cout << q << " " << y << " " << 2*q << " " << y/2 << "\n";
			continue;
		}
		vector<ll> divs;
		for (ll w = 1; w * w <= lo * q; w++)
		{
			if ((lo * q) % w == 0)
			{
				divs.push_back(w);
				divs.push_back((lo*q)/w);
			}
		}
		bool good = false;
		for (auto e : divs)
		{
			if (e > q && e <= n)
			{
				cout << q << " " << lo << " " << e << " " << q*lo/e << "\n";
				good = true;
				break;
			}
		}
		if (!good) cout << "-1\n";
	}
	bit fen(2*mn+20);
	ll lo = 2*m+1, hi = 2*m;
	for (ll q = n/2+1; q <= n; q++)
	{
		ll ylo = (l+q-1)/q, yhi = min(r/q,m);
		while (lo > ylo)
		{
			lo--;
			for (auto w : divisors[lo]) fen.update(w,1LL);
		}
		while (hi > yhi)
		{
			for (auto w : divisors[hi]) fen.update(w,-1LL);
			hi--;
		}
		if (ylo > yhi)
		{
			cout << "-1\n";
			continue;
		}
		bool found = false;
		for (auto w : divisors[q])
		{
			ll x = q/w;
			ll pref = fen.get(x);
			ll idx = fen.upper_bound(pref);
			if (idx > min(n,r)/w) continue;
			ll y1 = idx * ((ylo+idx-1)/idx), x2 = w*idx, y2 = q*y1/x2;
			cout << q << " " << y1 << " " << x2 << " " << y2 << "\n";
			found = true;
			break;
		}
		if (!found) cout << "-1\n";
	}
	return 0;
}
