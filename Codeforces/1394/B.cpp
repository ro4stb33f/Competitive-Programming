#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll md[3];
struct hhash{
	ll a[3];
	hhash()
	{
		fill(a, a+3, 0LL);
	}
	hhash(ll x)
	{
		for (int q = 0; q < 3; q++) a[q] = (x%md[q]+md[q])%md[q];
	}
	hhash operator+(const hhash& h)
	{
		hhash ret;
		ret.a[0] = (a[0]+h.a[0])%md[0];
		ret.a[1] = (a[1]*h.a[1])%md[1];
		ret.a[2] = (a[2]+h.a[2])%md[2];
		return ret;
	}
	bool operator==(const hhash& h)
	{
		for (int q = 0; q < 3; q++) if (h.a[q] != a[q]) return false;
		return true;
	}
};
hhash cur, pos[10][10];
const int mx = 2e5;
int k, ans = 0;
vector<pair<ll,ll>> adj[mx+1];
void dfs(int p, hhash h)
{
	if (p == k+1)
	{
		if (h == cur) ans++;
		return;
	}
	for (int q = 1; q <= p; q++) dfs(p+1, h+pos[p][q]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	md[0] = 998244353;
	md[1] = 1e9+7;
	md[2] = uniform_int_distribution<ll>(1e8,1e9)(rng);
	int n,m;
	cin >> n >> m >> k;
	for (int q = 0; q < m; q++)
	{
		ll a,b,w;
		cin >> a >> b >> w;
		adj[a].emplace_back(w,b);
	}
	hhash val[n+1];
	uniform_int_distribution<ll> gen(1, 1e18);
	for (int q = 1; q <= n; q++)
	{
		val[q] = hhash(gen(rng));
		cur = cur + val[q];
	}
	for (int q = 1; q <= n; q++) sort(adj[q].begin(), adj[q].end());
	for (int q = 1; q <= n; q++)
	{
		int sz = adj[q].size();
		for (int w = 0; w < sz; w++)
		{
			ll x = adj[q][w].second;
			pos[sz][w+1] = pos[sz][w+1] + val[x];
		}
	}
	dfs(1, hhash());
	cout << ans << "\n";
	return 0;
}
