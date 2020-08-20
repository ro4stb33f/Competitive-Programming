#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1e14;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,l;
	cin >> n >> m >> l;
	vector<vector<ll>> dist(n+1, vector<ll>(n+1, inf));
	for (int q = 0; q < m; q++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			for (int e = 1; e <= n; e++)
			{
				dist[w][e] = min(dist[w][e], dist[w][q]+dist[q][e]);
			}
		}
	}
	vector<vector<ll>> norefuel(n+1, vector<ll>(n+1, inf));
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			if (dist[q][w] <= l)
			{
				norefuel[q][w] = 1;
			}
		}
	}
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			for (int e = 1; e <= n; e++)
			{
				norefuel[w][e] = min(norefuel[w][e], norefuel[w][q] + norefuel[q][e]);
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int a,b;
		cin >> a >> b;
		cout << (norefuel[a][b] == inf ? -1 : norefuel[a][b]-1) << "\n";
	}
	return 0;
}
