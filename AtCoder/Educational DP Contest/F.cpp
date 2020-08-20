#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s,t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(m+1));
	for (int q = 1; q <= n; q++)
	{
		dp[q][0].second = 2;
	}
	for (int q = 1; q <= m; q++)
	{
		dp[0][q].second = 3;
	}
	for (int q = 1; q <= n; q++)
	{
		for (int w = 1; w <= m; w++)
		{
			if (s[q-1] == t[w-1])
			{
				dp[q][w] = {dp[q-1][w-1].first + 1, 1};
			}
			else
			{
				if (dp[q-1][w] > dp[q][w-1])
				{
					dp[q][w] = {dp[q-1][w].first, 2};
				}
				else
				{
					dp[q][w] = {dp[q][w-1].first, 3};
				}
			}
		}
	}
	vector<char> ans;
	int x = n, y = m;
	while (x != 0 || y != 0)
	{
		if (x > 0 && y > 0)
		{
			if (s[x-1] == t[y-1])
			{
				ans.push_back(s[x-1]);
			}
		}
		if (dp[x][y].second == 1)
		{
			x--;
			y--;
		}
		else if (dp[x][y].second == 2)
		{
			x--;
		}
		else
		{
			y--;
		}
	}
	for (int q = ans.size()-1; q >= 0; q--)
	{
		cout << ans[q];
	}
	cout << "\n";
	return 0;
}
