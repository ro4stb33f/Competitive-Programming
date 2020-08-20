#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> ct(2);
	for (int q = 0; q < n; q++)
	{
		ct[s[q]-'A']++;
	}
	if (abs(ct[0]-ct[1]) == 1)
	{
		cout << "Y\n";
	}
	else
	{
		cout << "N\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("alchemy_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ": ";
		solve();
	}
	return 0;
}
