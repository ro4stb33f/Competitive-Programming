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
	string s;
	cin >> s;
	int s0 = 0;
	int ptr = 0;
	while (ptr < n && s[ptr] != '1')
	{
		s0++;
		ptr++;
	}
	int e1 = 0;
	int ptr1 = n-1;
	while (ptr1 >= 0 && s[ptr1] != '0')
	{
		e1++;
		ptr1--;
	}
	if (ptr >= ptr1+1)
	{
		cout << s << "\n";
		return;
	}
	for (int q = 0; q < s0; q++)
	{
		cout << "0";
	}
	cout << "0";
	for (int q = 0; q < e1; q++)
	{
		cout << "1";
	}
	cout << "\n";
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

