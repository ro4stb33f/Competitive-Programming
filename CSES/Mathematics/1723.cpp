#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int mx = 100;
int n;
void mult(ll a[mx][mx], ll b[mx][mx])
{
	ll temp[n][n];
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			temp[q][w] = 0;
			for (int e = 0; e < n; e++)
			{
				temp[q][w] = (temp[q][w] + (a[q][e] * b[e][w]) % md) % md;
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
	ll m,k;
	cin >> n >> m >> k;
	ll adj[mx][mx];
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < n; w++)
		{
			adj[q][w] = 0;
		}
	}
	for (int q = 0; q < m; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a-1][b-1]++;
	}
	pow(adj,k);
	cout << adj[0][n-1] << "\n";
	return 0;
}
