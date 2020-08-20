#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<int> adj[mx+1];
vector<int> mxh(mx+1);
vector<int> ans(mx+1,-1);
void dfs(int v, int p)
{
	int d = 0;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a,v);
			d = max(d, 1+mxh[a]);
		}
	}
	mxh[v] = d;
}

void treedp(int v)
{
	vector<pair<int,int>> heights;
	for (int a : adj[v])
	{
		heights.emplace_back(mxh[a], a);
	}
	int sz = heights.size();
	sort(heights.begin(), heights.end());
	ans[v] = 1+heights.back().first;
	int temp = mxh[v];
	for (int a : adj[v])
	{
		if (ans[a] == -1)
		{
			if (heights.back().second == a)
			{
				if (sz == 1)
				{
					mxh[v] = 0;
				}
				else
				{
					mxh[v] = 1+heights[sz-2].first;
				}
				treedp(a);
				mxh[v] = temp;
			}
			else
			{
				mxh[v] = 1+heights[sz-1].first;
				treedp(a);
				mxh[v] = temp;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int q = 0; q < n-1; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (n==1)
	{
		cout << "0\n";
		return 0;
	}
	dfs(1,0);
	treedp(1);
	for (int q = 1; q <= n; q++)
	{
		cout << ans[q] << " ";
	}
	cout << "\n";
	return 0;
}
