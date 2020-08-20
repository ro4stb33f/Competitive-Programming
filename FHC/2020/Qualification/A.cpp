#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	string allowed[2];
	cin >> allowed[0] >> allowed[1];
	vector<vector<bool>> ans(n, vector<bool>(n));
	for (int q = 0; q < n; q++)
	{
		ans[q][q] = true;
		if (allowed[1][q]=='N')
		{
			for (int w = 0; w < n; w++)
			{
				cout << (ans[q][w]==true ? "Y" : "N");
			}
			cout << "\n";
			continue;
		}
		int cur = q-1;
		while (cur >= 0 && allowed[0][cur]=='Y')
		{
			ans[q][cur] = true;
			if (allowed[1][cur]=='N')
			{
				break;
			}
			cur--;
		}
		cur = q+1;
		while (cur < n && allowed[0][cur]=='Y')
		{
			ans[q][cur] = true;
			if (allowed[1][cur]=='N')
			{
				break;
			}
			cur++;
		}
		for (int w = 0; w < n; w++)
		{
			cout << (ans[q][w]==true ? "Y" : "N");
		}
		cout << "\n";
	}
}

int main()
{
	freopen("travel_restrictions_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ":\n";
		solve();
	}
	return 0;
}
