#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 500005;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> adj[mx];
	vector<int> smallestnotneighbor(mx, 1);
	vector<int> valneeded[mx];
	for (int q = 0; q < m; q ++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int q = 1; q <= n; q ++)
	{
		int a;
		cin >> a;
		valneeded[a].push_back(q);
	}
	vector<int> ans;
	for (int q = 1; q < mx; q++)
	{
		for (int a : valneeded[q])
		{
			if (q != smallestnotneighbor[a])
			{
				cout << "-1\n";
				return 0;
			}
			for (int b : adj[a])
			{
				if (smallestnotneighbor[b] == q)
				{
					smallestnotneighbor[b]++;
				}
			}
			ans.push_back(a);
		}
	}
	for (int q = 0; q < ans.size(); q++)
	{
		cout << ans[q] << " ";
	}
	return 0;
}
