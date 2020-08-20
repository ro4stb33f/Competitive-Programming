#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<pair<int,int>> order(mx+1);
vector<int> adj[mx+1];
vector<int> bit(mx+1);
int t = 0;

void update(int i, int inc)
{
	while (i <= mx)
	{
		bit[i] += inc;
		i += (i&-i);
	}
}

int get(int i)
{
	int ans = 0;
	while (i >= 1)
	{
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void dfs(int v, int p)
{
	t++;
	order[v].first = t;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a,v);
		}
	}
	order[v].second = t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for (int q = 1; q <= n; q++)
	{
		int a;
		cin >> a;
		v.emplace_back(a,q);
	}
	sort(v.begin(), v.end());
	vector<int> a(n+1);
	a[v[0].second] = 1;
	int cur = 1;
	for (int q = 1; q < n; q++)
	{
		if (v[q].first != v[q-1].first)
		{
			cur++;
		}
		a[v[q].second] = cur;
	}
	for (int q = 0; q < n-1; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	vector<int> dfsorder(n+1);
	for (int q = 1; q <= n; q++)
	{
		dfsorder[order[q].first] = a[q];
	}
	vector<int> lastseen(mx+1, -1);
	vector<int> ans(n+1);
	vector<tuple<int,int,int>> queries;
	for (int q = 1; q <= n; q++)
	{
		queries.emplace_back(order[q].second, order[q].first, q);
	}
	sort(queries.begin(), queries.end());
	cur = 0;
	for (int q = 0; q < n; q++)
	{
		int a,b,c;
		tie(a,b,c) = queries[q];
		while (cur < a)
		{
			cur++;
			if (lastseen[dfsorder[cur]] != -1)
			{
				update(lastseen[dfsorder[cur]], -1);
			}
			update(cur,1);
			lastseen[dfsorder[cur]] = cur;
		}
		ans[c] = get(a)-get(b-1);
	}
	for (int q = 1; q <= n; q++)
	{
		cout << ans[q] << " ";
	}
	cout << "\n";
	return 0;
}
