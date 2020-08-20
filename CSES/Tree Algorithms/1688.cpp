#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<int> adj[mx+1];
vector<vector<int>> anc(mx+1, vector<int>(20));
vector<int> depth(mx+1,-1);
int n;
void build()
{
	for (int w = 1; w < 20; w++)
	{
		for (int q = 1; q <= n; q++)
		{
			anc[q][w] = anc[anc[q][w-1]][w-1];
		}
	}
}

int get(int v, int x)
{
	int cur = v;
	for (int q = 0; q < 20; q++)
	{
		if (((1<<q)&x) > 0)
		{
			cur = anc[cur][q];
		}
	}
	if (cur == 0)
	{
		return -1;
	}
	return cur;
}

void dfs(int v)
{
	for (int a : adj[v])
	{
		if (depth[a] == -1)
		{
			depth[a] = depth[v]+1;
			dfs(a);
		}
	}
}

int lca(int a, int b)
{
	if (depth[a] > depth[b])
	{
		swap(a,b);
	}
	if (depth[a] != depth[b])
	{
		b = get(b,depth[b]-depth[a]);
	}
	if (a==b)
	{
		return a;
	}
	for (int q = 19; q >= 0; q--)
	{
		if (anc[a][q] != 0 && anc[b][q] != 0 && anc[a][q] != anc[b][q])
		{
			a = anc[a][q];
			b = anc[b][q];
		}
	}
	return anc[a][0];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	for (int w = 2; w <= n; w++)
	{
		cin >> anc[w][0];
		adj[anc[w][0]].push_back(w);
	}
	build();
	depth[1] = 0;
	dfs(1);
	for (int w = 0; w < q; w++)
	{
		int e,r;
		cin >> e >> r;
		cout << lca(e,r) << "\n";
	}
	return 0;
}	
