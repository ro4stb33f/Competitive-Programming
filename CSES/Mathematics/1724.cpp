#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int mx = 100;
const ll inf = LLONG_MAX;
int n;
void mult(ll a[mx][mx], ll b[mx][mx])
{
	ll temp[n][n];
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			temp[q][w] = inf;
			for (int e = 0; e < n; e++)
			{
				if (a[q][e] == inf || b[e][w] == inf)
				{
					continue;
				}
				temp[q][w] = min(temp[q][w], a[q][e]+b[e][w]);
			}
		}
	}
	for (int q = 0; q < n; q++)
	{
		for (int w=  0; w < n; w++)
		{
			a[q][w] = temp[q][w];
		}
	}
}

void pow(ll a[mx][mx], ll b)
{
	if (b <= 1)
	{
		return;
	}
	ll temp[mx][mx];
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			temp[q][w] = a[q][w];
		}
	}
	pow(a,b/2);
	mult(a,a);
	if (b % 2 == 1)
	{
		mult(a,temp);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll m,k;
	cin >> n >> m >> k;
	ll adj[mx][mx];
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			adj[q][w] = inf;
		}
	}
	for (int q = 0; q < m; q++)
	{
		int a,b;
		ll c;
		cin >> a >> b >> c;
		adj[a-1][b-1] = min(adj[a-1][b-1], c);
	}
	pow(adj,k);
	cout << (adj[0][n-1] == inf ? -1 : adj[0][n-1]) << "\n";
	return 0;
}
