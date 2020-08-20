#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 5e17;
const int mx = 2500;
vector<int> visited(mx+1);
vector<int> radj[mx+1];
void dfs(int v)
{
	visited[v] = true;
	for (int a : radj[v])
	{
		if (!visited[a])
		{
			dfs(a);
		}
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<tuple<int, int, ll>> edges;
	for (int q = 0; q < m; q++)
	{
		int a,b;
		ll c;
		cin >> a >> b >> c;
		radj[b].push_back(a);
		edges.emplace_back(a,b,-c);
	}
	vector<ll> distance(n+1, inf);
	distance[1] = 0;
	vector<ll> zero(n+1);
	vector<bool> pos(n+1);
	for (int q = 0; q < 2; q++)
	{
		for (int r = 1; r <= n-1; r++)
		{
			for (auto e : edges)
			{
				int a,b;
				ll w;
				tie(a,b,w) = e;
				if (distance[a] != inf)
				{
					distance[b] = min(distance[b], distance[a]+w);
				}
			}
		}
		if (q == 0)
		{
			for (int r = 1; r <= n; r++)
			{
				zero[r] = distance[r];
			}
		}
		else
		{
			for (int r = 1; r <= n; r++)
			{
				if (distance[r] < zero[r])
				{
					pos[r] = true;
				}
			}
		}
	}
	dfs(n);
	bool negcycle = false;
	for (int q = 1; q <= n; q++)
	{
		if (pos[q] && visited[q])
		{
			negcycle = true;
			break;
		}
	}
	if (negcycle)
	{
		cout << "-1\n";
	}
	else
	{
		cout << -distance[n] << "\n";
	}
	return 0;
}
