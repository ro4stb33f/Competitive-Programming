#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	vector<pair<int,ll>> adj[n+1];
	for (int q = 0; q < m; q++)
	{
		int a,b;
		ll c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b,c);
	}
	vector<int> visited(n+1);
	priority_queue<pair<ll, int>> pq;
	pq.push({0,1});
	while (!pq.empty())
	{
		int a;
		ll w;
		tie(w,a) = pq.top();
		pq.pop();
		w *= -1;
		if (visited[a] > k)
		{
			continue;
		}
		visited[a]++;
		if (a == n)
		{
			cout << w << " ";
			if (visited[a] == k)
			{
				break;
			}
		}
		for (auto e : adj[a])
		{
			int b;
			ll w1;
			tie(b,w1) = e;
			if (visited[b] <= k)
			{
				pq.push({-1 * (w+w1), b});
			}
		}
	}
	return 0;
}
