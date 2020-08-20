#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
vector<int> adj[2*mx+5];
vector<int> radj[2*mx+5];
vector<bool> visited(2*mx+5);
vector<int> comp(2*mx+5);
vector<int> comps[2*mx+5];
vector<int> topsort;
vector<int> ans(mx+5);
int curcomp = 0;
int m;

int opp(int x)
{
	if (x > m)
	{
		return x-m;
	}
	else
	{
		return x+m;
	}
}

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
	comp[v] = curcomp;
	comps[curcomp].push_back(v);
	for (int a : radj[v])
	{
		if (comp[a] == 0)
		{
			dfs2(a);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> m;
	for (int q = 0; q < n; q++)
	{
		char c, c1;
		int t, t1;
		cin >> c >> t >> c1 >> t1;
		if (c == '-')
		{
			t = opp(t);
		}
		if (c1 == '-')
		{
			t1 = opp(t1);
		}
		adj[opp(t)].push_back(t1);
		adj[opp(t1)].push_back(t);
		radj[t1].push_back(opp(t));
		radj[t].push_back(opp(t1));
	}
	for (int q = 1; q <= 2*m; q++)
	{
		if (!visited[q])
		{
			dfs(q);
		}
	}
	reverse(topsort.begin(), topsort.end());
	for (int q = 0; q < 2*m; q++)
	{
		if (comp[topsort[q]] == 0)
		{
			curcomp++;
			dfs2(topsort[q]);
		}
	}
	for (int q = 1; q <= m; q++)
	{
		if (comp[q] == comp[opp(q)])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	for (int q = curcomp; q >= 1; q--)
	{
		for (int v : comps[q])
		{
			if (v > m)
			{
				if (ans[opp(v)] == 0)
				{
					ans[opp(v)] = 1;
				}
			}
			else
			{
				if (ans[v] == 0)
				{
					ans[v] = 2;
				}
			}
		}
	}
	for (int q = 1; q <= m; q++)
	{
		if (ans[q] == 1)
		{
			cout << "- ";
		}
		else
		{
			cout << "+ ";
		}
	}
	cout << "\n";
	return 0;
}
