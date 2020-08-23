#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5;
vector<int> adj[mx+1];
vector<int> radj[mx+1];
vector<int> nadj[mx+1];
vector<int> topsort;
vector<int> ntopsort;
vector<int> col(mx+1);
vector<int> col2(mx+1);
void dfs(int v)
{
	col[v] = 1;
	for (int a : adj[v])
	{
		if (col[a] == 0) dfs(a);
	}
	col[v] = 2;
	topsort.push_back(v);
}

void dfs2(int v)
{
	col2[v] = 1;
	for (int a : nadj[v])
	{
		if (col2[a] == 0) dfs2(a);
	}
	col2[v] = 2;
	ntopsort.push_back(v);
}

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	ll a[n+1];
	for (int q = 1; q <= n; q++) cin >> a[q];
	for (int q = 1; q <= n; q++)
	{
		int x;
		cin >> x;
		if (x != -1)
		{
			adj[q].push_back(x);
		}	radj[x].push_back(q);
	}
	for (int q = 1; q <= n; q++)
	{
		if (col[q] == 0) dfs(q);
	}
	reverse(topsort.begin(), topsort.end());
	vector<ll> best(n+1);
	ll ans = 0;
	for (int q = 0; q < n; q++)
	{
		best[topsort[q]] = a[topsort[q]];
		for (int x : radj[topsort[q]])
		{
			if (best[x] >= 0)
			{
				best[topsort[q]] += best[x];
				nadj[x].push_back(topsort[q]);
			}
			else
				nadj[topsort[q]].push_back(x);
		}
		ans += best[topsort[q]];
	}
	for (int q = 1; q <= n; q++)
	{
		if (col2[q] == 0) dfs2(q);
	}
	reverse(ntopsort.begin(), ntopsort.end());
	cout << ans << "\n";
	for (int x : ntopsort) cout << x << " ";
	cout << "\n";
	return 0;
}
