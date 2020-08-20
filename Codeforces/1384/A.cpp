#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	int l = 200;
	string s;
	for (int q = 0; q < l; q++)
	{
		s+="a";
	}
	cout << s << "\n";
	for (int q = 1; q < n+1; q++)
	{
		int common = a[q-1];
		for (int w = common; w < l; w++)
		{
			int val = s[w]-'a';
			val = (val+1)%26;
			s[w] = (char)('a'+val);
		}
		cout << s << "\n";
	}
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

