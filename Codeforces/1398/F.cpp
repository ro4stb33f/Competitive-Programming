#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> maxlen(n+1, vector<int>(2));
	for (int q = n-1; q >= 0; q--)
	{
		for (int w = 0; w < 2; w++)
		{
			if (s[q] != (char)('0'+1-w)) maxlen[q][w] = 1+maxlen[q+1][w];
		}
	}
	vector<vector<vector<int>>> blocks(n+1, vector<vector<int>>(2));
	for (int w = 0; w < 2; w++)
	{
		int l = 0, r = 0;
		while (l < n)
		{
			if (s[l] == (char)('0'+1-w))
			{
				l++;
				r++;
				continue;
			}
			if (l == 0 || s[l-1] == (char)('0'+1-w))
			{
				while (r < n && s[r] != (char)('0'+ 1-w)) r++;
				for (int q = l; q < r; q++) blocks[q-l+1][w].push_back(l);
				l = r;
				continue;
			}
			l++;
			r++;
		}
	}
	for (int q = 1; q <= n; q++)
	{
		int ans = 0;
		int ptr[2], pos = 0;
		ptr[0] = 0, ptr[1] = 0;
		while (pos < n)
		{
			int closest = INT_MAX;
			for (int w = 0; w < 2; w++)
			{
				if (maxlen[pos][w] >= q)
				{
					closest = pos;
					break;
				}
				while (ptr[w] < (int)blocks[q][w].size() && blocks[q][w][ptr[w]] < pos) ptr[w]++;
				if (ptr[w] < (int)blocks[q][w].size()) closest = min(closest, blocks[q][w][ptr[w]]);
			}
			if (closest == INT_MAX) break;
			pos = closest + q;
			ans++;
		}
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}
