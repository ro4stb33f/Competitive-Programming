#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve()
{
	int n,x;
	cin >> n >> x;
	vector<int> adj[n+1];
	for (int q = 0; q < n-1; q++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (adj[x].size() <= 1)
	{
		cout << "Ayush\n";
		return;
	}
	if ((n-1) % 2 == 0)
	{
		cout << "Ashish\n";
	}
	else
	{
		cout << "Ayush\n";
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
