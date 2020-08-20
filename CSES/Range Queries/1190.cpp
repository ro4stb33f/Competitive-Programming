#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5;
vector<ll> sum(3*mx+1);
vector<ll> pref(3*mx+1);
vector<ll> suff(3*mx+1);
vector<ll> sub(3*mx+1);
void update(int a, int b, int k, int l, int r, int v)
{
	if (a > r || b < l)
	{
		return;
	}
	if (a <= l && r <= b)
	{
		sum[k]=v;
		pref[k]=max(0,v);
		suff[k]=max(0,v);
		sub[k]=max(0,v);
		return;
	}
	int m = (l+r)/2;
	update(a,b,2*k,l,m,v);
	update(a,b,2*k+1,m+1,r,v);
	sum[k]=sum[2*k]+sum[2*k+1];
	pref[k]=max(pref[2*k],sum[2*k]+pref[2*k+1]);
	suff[k]=max(suff[2*k+1],sum[2*k+1]+suff[2*k]);
	sub[k]=max(max(sub[2*k],sub[2*k+1]),suff[2*k]+pref[2*k+1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int q = 0; q < n; q++)
	{
		ll a;
		cin >> a;
		update(q,q,1,0,n-1,a);
	}
	for (int q = 0; q < m; q++)
	{
		ll k,x;
		cin >> k >> x;
		update(k-1,k-1,1,0,n-1,x);
		cout << sub[1] << "\n";
	}
	return 0;
}
