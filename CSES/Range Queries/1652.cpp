#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin >> n >> q;
	vector<vector<int>> treect(n+1, vector<int>(n+1));
	for (int w = 1; w <= n; w++)
	{
		string s;
		cin >> s;
		for (int e = 1; e <= n; e++)
		{
			treect[w][e] = treect[w-1][e] + treect[w][e-1] - treect[w-1][e-1];
			if (s[e-1] == '*')
			{
				treect[w][e]++;
			}
		}
	}
	for (int w = 0; w < q; w++)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int res = treect[y2][x2] -(treect[y1-1][x2] + treect[y2][x1-1] - treect[y1-1][x1-1]);
		cout << res << "\n";
	}
	return 0;
}
