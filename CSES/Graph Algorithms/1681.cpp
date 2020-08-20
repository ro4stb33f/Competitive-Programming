#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int mx = 1e5;
vector<int> adj[mx+1];
vector<int> radj[mx+1];
vector<int> topsort;
vector<int> visited(mx+1);
void dfs(int v)
{
	visited[v] = 1;
	for (int a : adj[v])
	{
		if (visited[a] == 0)
		{
			dfs(a);
		}
	}
	visited[v] = 2;
	topsort.push_back(v);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	for (int q = 1; q <= n; q++)
	{
		if (visited[q] == 0)
		{
			dfs(q);
		}
	}
	reverse(topsort.begin(), topsort.end());
	vector<ll> dp(n+1);
	for (int q = 0; q < n; q++)
	{
		if (topsort[q] == 1)
		{
			dp[1] = 1;
		}
		else
		{
			for (int a : radj[topsort[q]])
			{
				if (dp[a] > 0)
				{
					dp[topsort[q]] = (dp[topsort[q]]+dp[a])%md;
				}
			}
		}
	}
	cout << dp[n] << "\n";
	return 0;
}
