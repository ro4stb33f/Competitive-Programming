#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<vector<int>> anc(mx+1, vector<int>(20));
int n;
void build()
{
	for (int w = 1; w < 20; w++)
	{
		for (int q = 1; q <= n; q++)
		{
			anc[q][w] = anc[anc[q][w-1]][w-1];
		}
	}
}

int get(int v, int x)
{
	int cur = v;
	for (int q = 0; q < 20; q++)
	{
		if (((1<<q)&x) > 0)
		{
			cur = anc[cur][q];
		}
	}
	if (cur == 0)
	{
		return -1;
	}
	return cur;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	for (int w = 2; w <= n; w++)
	{
		cin >> anc[w][0];
	}
	build();
	for (int w = 0; w < q; w++)
	{
		int e,r;
		cin >> e >> r;
		cout << get(e,r) << "\n";
	}
	return 0;
}	
