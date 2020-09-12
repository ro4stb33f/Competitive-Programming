#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mx = 1e5;
vector<int> adj[mx+1];
vector<int> centroids;
vector<int> subtreesz(mx+1);
int n;
void dfs(int v, int p)
{
	subtreesz[v] = 1;
	bool greater = false;
	for (int a : adj[v])
	{
		if (a == p) continue;
		dfs(a,v);
		subtreesz[v] += subtreesz[a];
		if (subtreesz[a] > n/2) greater = true;
	}
	if (!greater && n-subtreesz[v] <= n/2) centroids.push_back(v);
}

void solve()
{
	cin >> n;
	for (int q = 1; q <= n; q++) adj[q].clear();
	centroids.clear();
	for (int q = 0; q < n-1; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	int sz = centroids.size();
	assert(sz <= 2);
	if (sz == 1)
	{
		cout << 1 << " " << adj[1][0] << "\n";
		cout << 1 << " " << adj[1][0] << "\n";
		return;
	}
	int x = centroids[0], y = centroids[1];
	if (subtreesz[x] <= subtreesz[y]) swap(x,y);
	int xrem = n - subtreesz[y];
	if (xrem <= n/2)
	{
		int rem = -1;
		for (int a : adj[x])
		{
			if (a == y) continue;
			rem = a;
			break;
		}
		cout << x << " " << rem << "\n";
		cout << y << " " << rem << "\n";
		return;
	}
	int rem = -1;
	for (int a : adj[y])
	{
		if (a == x) continue;
		rem = a;
		break;
	}
	cout << y << " " << rem << "\n";
	cout << x << " " << rem << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

