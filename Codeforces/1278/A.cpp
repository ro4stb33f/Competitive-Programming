#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	string s;
	string t;
	cin >> s >> t;
	int tl = t.length(), sl = s.length();
	vector<vector<int>> ct(tl+1, vector<int>(26));
	for (int q = 0; q < tl; q++)
	{
		for (int w = 0; w < 26; w++)
		{
			ct[q+1][w] = ct[q][w];
		}
		ct[q+1][t[q]-'a']++;
	}
	vector<int> ct1(26);
	for (int q = 0; q < sl; q++)
	{
		ct1[s[q]-'a']++;
	}
	for (int q = 0; q <= tl; q++)
	{
		for (int w = q+1; w <= tl; w++)
		{
			bool good = true;
			for (int e = 0; e < 26; e++)
			{
				if (ct[w][e] - ct[q][e] != ct1[e])
				{
					good = false;
					break;
				}
			}
			if (good)
			{
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

