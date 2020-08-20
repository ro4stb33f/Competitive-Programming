#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1);
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int s,f,r;
	cin >> s >> f >> r;
	vector<int> rdist(n+1, -1);
	rdist[r] = 0;
	queue<int> bfs;
	bfs.push(r);
	while (!bfs.empty())
	{
		int t = bfs.front();
		bfs.pop();
		for (int a : adj[t])
		{
			if (rdist[a] == -1)
			{
				rdist[a] = rdist[t]+1;
				bfs.push(a);
			}
		}
	}
	vector<int> sdist(n+1, -2);
	vector<int> dp(n+1,-1);
	sdist[s] = 0;
	queue<int> bfs2;
	bfs2.push(s);
	while (!bfs2.empty())
	{
		int t = bfs2.front();
		bfs2.pop();
		int mxothers = INT_MIN;
		for (int a : adj[t])
		{
			if (sdist[a]+1 == sdist[t])
			{
				mxothers = max(mxothers, dp[a]);
			}
			else if (sdist[a] == -2)
			{
				sdist[a] = sdist[t]+1;
				bfs2.push(a);
			}
		}
		if (mxothers == INT_MIN)
		{
			dp[t] = rdist[t];
		}
		else
		{
			dp[t] = min(mxothers, rdist[t]);
		}
	}
	cout << dp[f] << "\n";
	return 0;
}
