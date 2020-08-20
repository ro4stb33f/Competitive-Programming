#include <bits/stdc++.h>
using namespace std;
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
	vector<pair<int,int>> dp(n+1);
	for (int q = 0; q < n; q++)
	{
		if (topsort[q] == 1)
		{
			dp[1].first = 1;
		}
		else
		{
			for (int a : radj[topsort[q]])
			{
				if (dp[a].first > 0 && dp[a].first >= dp[topsort[q]].first)
				{
					dp[topsort[q]].first = dp[a].first+1;
					dp[topsort[q]].second = a;
				}
			}
		}
	}
	if (dp[n].first == 0)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ans;
	ans.push_back(n);
	cout << dp[n].first << "\n";
	int cur = dp[n].second;
	while (cur != 0)
	{
		ans.push_back(cur);
		cur = dp[cur].second;
	}
	reverse(ans.begin(), ans.end());
	for (int q : ans)
	{
		cout << q << " ";
	}
	cout << "\n";
	return 0;
}
