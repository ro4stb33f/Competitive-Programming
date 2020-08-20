#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;
const ll mx = 2e5;
vector<ll> fact(mx+1);
vector<ll> invfact(mx+1);
ll pow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	ll ans = pow(a,b/2);
	ans = (ans * ans)%md;
	if (b%2==1)
	{
		ans = (ans * a)%md;
	}
	return ans;
}

ll choose(ll a, ll b)
{
	if (b > a)
	{
		return 0LL;
	}
	return (((fact[a]*invfact[b]) % md)*invfact[a-b])%md;
}

int main()
{
	fact[0] = 1;
	invfact[0] = 1;
	for (ll q = 1; q <= mx; q++)
	{
		fact[q] = (fact[q-1] * q) % md;
		invfact[q] = pow(fact[q], md-2);
	}
	ll h,w,n;
	cin >> h >> w >> n;
	vector<pair<ll,ll>> walls;
	for (int q = 0; q < n; q++)
	{
		ll a,b;
		cin >> a >> b;
		walls.emplace_back(a,b);
	}
	walls.emplace_back(h,w);
	sort(walls.begin(), walls.end());
	vector<ll> dp(n+1);
	for (int q = 0; q <= n; q++)
	{
		dp[q] = choose(walls[q].first+walls[q].second-2, walls[q].first-1);
	}
	for (int q = 1; q <= n; q++)
	{
		for (int w = 0; w < q; w++)
		{
			if (walls[w].second > walls[q].second)
			{
				continue;
			}
			ll dx = walls[q].first-walls[w].first;
			ll dy = walls[q].second-walls[w].second;
			dp[q] = (dp[q] - ((dp[w] * choose(dx+dy, dx))%md))%md;
		}
	}
	cout << ((dp[n]%md)+md)%md << "\n";
	return 0;
}
