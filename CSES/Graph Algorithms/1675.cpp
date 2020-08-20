#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int comps;
vector<int> sz;
vector<int> par;

int root(int a)
{
	if (par[a] == a)
	{
		return a;
	}
	return par[a] = root(par[a]);
}

bool unite(int a, int b)
{
	int a1 = root(a), b1 = root(b);
	if (a1 == b1)
	{
		return false;
	}
	if (sz[a1] > sz[b1])
	{
		swap(a1,b1);
	}
	sz[a1]+=sz[b1];
	par[b1]=a1;
	comps--;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	comps = n;
	for (int q = 0; q <= n; q++)
	{
		sz.push_back(1);
		par.push_back(q);
	}
	priority_queue<tuple<ll,int,int>> pq;
	for (int q = 0; q < m; q++)
	{
		int a,b;
		ll c;
		cin >> a >> b >> c;
		pq.push({-c,a,b});
	}
	ll tot = 0;
	for (int q = 0; q < m; q++)
	{
		auto e = pq.top();
		pq.pop();
		int a,b;
		ll c;
		tie(c,a,b)=e;
		if (unite(a,b))
		{
			tot -= c;
		}
		if (comps == 1)
		{
			break;
		}
	}
	if (comps != 1)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << tot << "\n";
	}
	return 0;
}
