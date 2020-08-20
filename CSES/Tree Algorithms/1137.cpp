#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5;
vector<ll> val(mx+1);
vector<ll> dfsseq(mx+1);
vector<int> adj[mx+1];
vector<pair<int,int>> order(mx+1);
int t = 0;
int n;
void update(int i, ll inc)
{
	while (i <= n)
	{
		dfsseq[i]+=inc;
		i+=(i&-i);
	}
}

ll get(int i)
{
	ll ans = 0;
	while (i >= 1)
	{
		ans += dfsseq[i];
		i-=(i&-i);
	}
	return ans;
}

void dfs(int v, int p)
{
	t++;
	order[v].first = t;
	update(t,val[v]);
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a,v);
		}
	}
	order[v].second = t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	for (int w = 1; w <= n; w++)
	{
		cin >> val[w];
	}
	for (int w = 0; w < n-1; w++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	for (int w = 0; w < q; w++)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			int a;
			ll b;
			cin >> a >> b;
			update(order[a].first, b-val[a]);
			val[a] = b;
		}
		else
		{
			int a;
			cin >> a;
			cout << get(order[a].second) - get(order[a].first-1) << "\n";
		}
	}
	return 0;
}
