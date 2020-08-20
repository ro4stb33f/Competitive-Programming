#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;
const int mx = 1e5+3;
vector<int> adj[mx];
ll black[mx];
ll white[mx];


void dfs(int v, int p)
{
	ll b = 1, w = 1;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a, v);
			b = (b * white[a]) % md;
			w = (w * ((black[a] + white[a])%md)) % md;
		}
	}
	black[v] = b;
	white[v] = w;
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
	dfs(1, 0);
	cout << (black[1] + white[1]) % md << "\n";
	return 0;
}
