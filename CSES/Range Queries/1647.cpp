#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,e;
	cin >> n >> e;
	int logs[n+1];
	logs[1] = 0;
	for (int q = 2; q <= n; q++)
	{
		logs[q] = logs[q/2] + 1;
	}
	int val[n];
	for (int q = 0; q < n; q++)
	{
		cin >> val[q];
	}
	vector<vector<int>> minsparse(n, vector<int>(20));
	for (int q = 0; q < n; q++)
	{
		minsparse[q][0] = val[q];
	}
	for (int q = 1; q < 20; q++)
	{
		for (int w = 0; w + (1<<q) - 1 < n; w++)
		{
			minsparse[w][q] = min(minsparse[w][q-1], minsparse[w+(1<<(q-1))][q-1]);
		}
	}
	for (int q = 0; q < e; q++)
	{
		int a,b;
		cin >> a >> b;
		int pow = logs[b-a+1];
		cout << min(minsparse[a-1][pow], minsparse[b-1-(1<<pow)+1][pow]) << "\n";
	}
	return 0;
}
