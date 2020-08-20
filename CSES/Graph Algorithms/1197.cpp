#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 5e17;
int main()
{
	int n,m;
	cin >> n >> m;
	vector<tuple<int,int,ll>> edges;
	for (int q = 1; q <= m; q++)
	{
		int a,b;
		ll w;
		cin >> a >> b >> w;
		edges.emplace_back(a,b,w);
	}
	vector<ll> dist(n+1, inf);
	int latest;
	vector<int> par(n+1);
	for (int q = 1; q <= n; q++)
	{
		latest = -1;
		for (auto e : edges)
		{
			int a,b;
			ll w;
			tie(a,b,w) = e;
			if (dist[a] + w < dist[b])
			{
				dist[b] = dist[a]+w;
				latest = b;
				par[b] = a;
			}
		}	
	}
	if (latest == -1)
	{
		cout << "NO\n";
		return 0;
	}
	for (int q = 1; q <= n; q++)
	{
		latest = par[latest];
	}
	vector<int> cycle;
	int cur = latest;
	while (cur != latest || cycle.size() == 0)
	{
		cycle.push_back(cur);
		cur = par[cur];
	}
	cycle.push_back(latest);
	reverse(cycle.begin(), cycle.end());
	cout << "YES\n";
	for (int q : cycle)
	{
		cout << q << " ";
	}
	cout << "\n";
	return 0;
}
