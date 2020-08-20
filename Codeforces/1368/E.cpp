#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mx = 2e5;	
vector<int> adj[mx+5];
vector<int> radj[mx+5];
vector<int> topsort;
vector<bool> visited(mx+5);

void dfs(int v)
{
	visited[v] = true;
	for (int u : adj[v])
	{
		if (!visited[u])
		{
			dfs(u);
		}
	}
	topsort.push_back(v);
}

void solve()
{
	int n,m;
	cin >> n >> m;
	for (int q = 1; q <= n; q++)
	{
		adj[q].clear();
		radj[q].clear();
	}
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	topsort.clear();
	for (int q = 1; q <= n; q++)
	{
		visited[q] = false;
	}
	for (int q = 1; q <= n; q++)
	{
		if (!visited[q])
		{
			dfs(q);
		}
	}
	reverse(topsort.begin(), topsort.end());
	vector<int> ans;
	vector<bool> closed(n+1);
	vector<int> dp(n+1);
	for (int q = 0; q < n; q++)
	{
		int longest = 0;
		for (int a : radj[topsort[q]])
		{
			if (!closed[a])
			{
				longest = max(longest, 1+dp[a]);
			}
		}
		if (longest >= 2)
		{
			ans.push_back(topsort[q]);
			closed[topsort[q]] = true;
		}
		else
		{
			dp[topsort[q]] = longest;
		}
	}
	int sz = ans.size();
	cout << sz << "\n";
	for (int q : ans)
	{
		cout << q << " ";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

