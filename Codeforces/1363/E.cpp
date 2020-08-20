#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 200005;
vector<ll> a(mx);
vector<ll> b(mx);
vector<ll> c(mx);
vector<int> adj[mx];
vector<int> swapsneeded(mx);
ll tot = 0;
pair<int,int> dfsinit(int v, int p)
{
	int zero1 = 0;
	int one0 = 0;
	for (int a : adj[v])
	{
		if (a != p)
		{
			pair<int,int> temp = dfsinit(a, v);
			zero1 += temp.first;
			one0 += temp.second;
		}
	}
	if (b[v] == 0 && c[v] == 1)
	{
		zero1++;
	}
	if (b[v] == 1 && c[v] == 0)
	{
		one0++;
	}
	swapsneeded[v] = min(zero1, one0);
	return make_pair(zero1, one0);
}

int dfs(int v, int p, ll curmin)
{
	ll tempmin = min(curmin, a[v]);
	int numswapped = 0;
	for (int a : adj[v])
	{
		if (a != p)
		{
			numswapped += dfs(a, v, tempmin);
		}
	}
	if (a[v] <= curmin)
	{
		int rem = swapsneeded[v] - numswapped;
		tot+=(2 * a[v] * rem);
		numswapped = swapsneeded[v];
	}
	return numswapped;
}

int main()
{
	int n;
	cin >> n;
	for (int q = 1; q <= n; q++)
	{
		cin >> a[q] >> b[q] >> c[q];
	}
	for (int q = 0; q < n-1; q++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	pair<int,int>  thing = dfsinit(1, 0);
	if (thing.first != thing.second)
	{
		cout << "-1\n";
		return 0;
	}
	dfs(1,0,a[1]);
	cout << tot <<"\n";
	return 0;
}
