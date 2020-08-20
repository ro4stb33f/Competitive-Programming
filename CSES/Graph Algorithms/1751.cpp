#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n+1, vector<int>(18));
	for (int w = 1; w <= n; w++)
	{
		cin >> adj[w][0];
	}
	for (int w = 1; w < 18; w++)
	{
		for (int e = 1; e <= n; e++)
		{
			adj[e][w] = adj[adj[e][w-1]][w-1];
		}
	}
	vector<int> belong(n+1);
	vector<int> cyclelen;
	cyclelen.push_back(-1);
	vector<int> pos(n+1);
	vector<int> entrypt(n+1);
	int curcycle = 1;
	for (int w = 1; w <= n; w++)
	{
		if (belong[w] != 0)
		{
			continue;
		}
		int cur = w;
		int ct = 0;
		while (belong[cur] == 0)
		{
			ct++;
			belong[cur] = curcycle;
			cur = adj[cur][0];
		}
		if (belong[cur] == curcycle)
		{
			//new cycle found
			int cur1 = w;
			int ct1 = 0;
			while (cur1 != cur)
			{
				ct1++;
				cur1 = adj[cur1][0];
			}
			cur1 = w;
			while (cur1 != cur)
			{
				pos[cur1] = -ct1;
				ct1--;
				entrypt[cur1] = cur;
				cur1 = adj[cur1][0];
			}
			int nlen = 1;
			pos[cur1] = nlen;
			cur1 = adj[cur1][0];
			while (cur1 != cur)
			{
				nlen++;
				pos[cur1] = nlen;
				cur1 = adj[cur1][0];
			}
			cyclelen.push_back(nlen);
			curcycle++;
		}
		else
		{
			bool notnew = false;
			if (pos[cur] < 0)
			{
				//connect to new entry
				notnew = true;
			}
			int cur1 = w;
			while (cur1 != cur)
			{
				if (notnew)
				{
					pos[cur1] = pos[cur]-ct;
					ct--;
					entrypt[cur1] = entrypt[cur];
				}
				else
				{
					//directly connected to new place on cycle
					pos[cur1] = -ct;
					ct--;
					entrypt[cur1] = cur;
				}
				belong[cur1] = belong[cur];
				cur1 = adj[cur1][0];
			}
		}
	}
	for (int q = 1; q <= n; q++)
	{
		if (pos[q] < 0)
		{
			cout << -pos[q] + cyclelen[belong[q]] << " ";
		}
		else
		{
			cout << cyclelen[belong[q]] << " ";
		}
	}
	cout << "\n";
	return 0;
}
