#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mx = 1e5+5;
const int inf = 1e6;
vector<int> adj[mx];
vector<int> depth(mx, inf);
vector<int> parent(mx, -1);
vector<int> color(mx);
int zero = 0;
int one = 0;
int cyclestart = -1, cycleend = -1;
bool dfs(int v)
{
	int mxdepth = -1;
	for (int a : adj[v])
	{
		if (a == parent[v])
		{
			continue;
		}
		if (depth[a] != inf)
		{
			if (depth[a] > mxdepth)
			{
				mxdepth = depth[a];
				cyclestart = a;
			}
		}
	}
	if (cyclestart != -1)
	{
		cycleend = v;
		return true;
	}
	for (int a : adj[v])
	{
		if (a == parent[v])
		{
			continue;
		}
		parent[a] = v;
		depth[a] = depth[v]+1;
		color[a] = 1-color[v];
		if (color[a] == 1)
		{
			one++;
		}
		else
		{
			zero++;
		}
		if (dfs(a))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for (int q = 1; q <= m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	depth[1] = 0;
	color[1] = 0;
	dfs(1);
	int req = (k+1)/2;
	if (cycleend == -1)
	{
		//no cycle
		int colorwanted = 0;
		if (one > zero)
		{
			colorwanted = 1;
		}
		cout << "1\n";
		int ct = 0;
		for (int q = 1; q <= n; q++)
		{
			if (ct < req)
			{
				if (color[q] == colorwanted)
				{
					cout << q << " ";
					ct++;
				}
			}
		}
		cout << "\n";
		return 0;
	}
	vector<int> cycle;
	int cur = cycleend;
	while (cur != cyclestart)
	{
		cycle.push_back(cur);
		cur = parent[cur];
	}
	cycle.push_back(cyclestart);
	if (cycle.size() <= k)
	{
		cout << "2\n" << cycle.size() << "\n";
		for (int q = 0; q < cycle.size(); q++)
		{
			cout << cycle[q] << " ";
		}
	}
	else
	{
		cout << "1\n";
		int curr = 0;
		int ct = 0;
		while (ct < req)
		{
			cout << cycle[curr] << " ";
			curr+=2;
			ct++;
		}
	}
	return 0;
}

