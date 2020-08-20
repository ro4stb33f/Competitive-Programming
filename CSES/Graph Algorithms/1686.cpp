#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e5;
vector<int> adj[mx+1];
vector<int> radj[mx+1];
vector<bool> visited(mx+1);
vector<int> topsort;
int curcomp = 0;
vector<int> comps[mx+1];
vector<int> comp(mx+1);
void dfs(int v)
{
	visited[v] = true;
	for (int a : adj[v])
	{
		if (!visited[a])
		{
			dfs(a);
		}
	}
	topsort.push_back(v);
}
void dfs2(int v)
{
	visited[v] = true;
	comps[curcomp].push_back(v);
	comp[v] = curcomp;
	for (int a : radj[v])
	{
		if (!visited[a])
		{
			dfs2(a);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<ll> val(n+1);
	for (int q = 1; q <= n; q++)
	{
		cin >> val[q];
	}
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	for (int q = 1; q <= n; q++)
	{
		if (!visited[q])
		{
			dfs(q);
		}
	}
	reverse(topsort.begin(), topsort.end());
	fill(visited.begin(), visited.end(), false);
	for (int q = 0; q < n; q++)
	{
		if (!visited[topsort[q]])
		{
			curcomp++;
			dfs2(topsort[q]);
		}
	}
	vector<ll> dp(curcomp+1);
	ll ans = 0;
	for (int q = 1; q <= curcomp; q++)
	{
		ll totval = 0;
		ll best = 0;
		for (int w : comps[q])
		{
			totval+= val[w];
			for (int a : radj[w])
			{
				best = max(best, dp[comp[a]]);
			}
		}
		dp[q] = best+totval;
		ans = max(ans, dp[q]);
	}
	cout << ans << "\n";
	return 0;
}
