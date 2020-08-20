#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5;
vector<int> adj[mx+1];
vector<ll> sumdist(mx+1);
vector<ll> ans(mx+1,-1);
vector<int> numnodes(mx+1);
int n;
void dfs(int v, int p)
{
	ll d = 0;
	int num = 1;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a,v);
			d += sumdist[a]+numnodes[a];
			num += numnodes[a];
		}
	}
	numnodes[v] = num;
	sumdist[v] = d;
}

void treedp(int v)
{
	ll tot = 0;
	for (int a : adj[v])
	{
		tot+=sumdist[a];
	}
	ans[v] = n-1+tot;
	sumdist[v] = ans[v];
	int t1 = numnodes[v];
	ll t2= sumdist[v];
	for (int a : adj[v])
	{
		if (ans[a] != -1)
		{
			continue;
		}
		numnodes[v] = n-numnodes[a];
		sumdist[v]  = sumdist[v]-numnodes[a]-sumdist[a];
		treedp(a);
		numnodes[v] = t1;
		sumdist[v] = t2;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
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
