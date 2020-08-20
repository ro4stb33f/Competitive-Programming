#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<vector<int>> go(mx+1, vector<int>(30));
int n;
void build()
{
	for (int q = 1; q < 30; q++)
	{
		for (int w = 1; w <= n; w++)
		{
			go[w][q] = go[go[w][q-1]][q-1];
		}
	}
}

int get(int i, int k)
{
	int cur = i;
	for (int q = 0; q < 30; q++)
	{
		if ((1<<q)&k)
		{
			cur = go[cur][q];
		}
	}
	return cur;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	for (int w = 1; w <= n; w++)
	{
		cin >> go[w][0];
	}
	build();
	for (int w = 0; w < q; w++)
	{
		int a,b;
		cin >> a >> b;
		cout << get(a,b) << "\n";
	}
	return 0;
}
