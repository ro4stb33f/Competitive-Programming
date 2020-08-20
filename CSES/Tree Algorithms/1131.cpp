#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<int> adj[mx+1];
int ans = 0;
vector<int> mxh(mx+1);
void dfs(int v, int p)
{
	int mh = -1, mh1 = -1;
	for (int a : adj[v])
	{
		if (a == p)
		{
			continue;
		}
		dfs(a,v);
		if (mxh[a] > mh)
		{
			mh1 = mh;
			mh = mxh[a];
		}
		else if (mxh[a] > mh1)
		{
			mh1 = mxh[a];
		}
	}
	if (mh == -1)
	{
		mxh[v] = 0;
		return;
	}
	if (mh1 == -1)
	{
		ans = max(ans, mh+1);
		mxh[v] = 1+mh;
		return;
	}
	mxh[v] = max(mh,mh1)+1;
	ans = max(ans, mh+mh1+2);
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
	dfs(1,0);
	cout << ans << "\n";
	return 0;
}
