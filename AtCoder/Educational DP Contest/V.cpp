#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e5+1;
vector<int> adj[mx];
vector<ll> treenum(mx);
vector<ll> pref[mx];
vector<ll> suff[mx];
ll m;
vector<ll> ans(mx);

void dfs(int v, int p)
{
	ll num = 1;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs(a, v);
			num = (num * (treenum[a]+1)) % m;
		}
	}
	treenum[v] = num;
}

void dp(int v, int p, int index)
{
	for (int a : adj[v])
	{
		if (a != p)
		{
			pref[v].push_back((treenum[a]+1)%m);
			suff[v].push_back((treenum[a]+1)%m);
		}
		else
		{
			ll temp = 1;
			if (index > 0)
			{
				temp = (temp * pref[p][index-1])%m;
			}
			if (index < suff[p].size()-1)
			{
				temp = (temp * suff[p][index+1])%m;
			}
			pref[v].push_back((temp+1)%m);
			suff[v].push_back((temp+1)%m);
		}
	}	
	int sz = pref[v].size();
	for (int q = 1; q < sz; q++)
	{
		pref[v][q] = (pref[v][q] * pref[v][q-1]) % m;
		suff[v][sz-q-1] = (suff[v][sz-q-1] * suff[v][sz-q]) % m;
	}
	ll num = treenum[v];
	if (p != 0)
	{
		ll prod = 1;
		if (index > 0)
		{
			prod = (prod * pref[p][index-1]) % m; 
		}
		if (index < suff[p].size()-1)
		{
			prod = (prod * suff[p][index+1]) % m;
		}
		num = (num * (prod+1)) % m;
	}
	ans[v] = num;
	int counter = 0;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dp(a, v, counter);
		}
		counter++;
	}
}

int main()
{
	ll n;
	cin >> n >> m;
	for (int q = 0; q < n-1; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	dp(1,0,0);
	for (int q = 1; q <= n; q++)
	{
		cout << ans[q] << "\n";
	}
	return 0;
}
