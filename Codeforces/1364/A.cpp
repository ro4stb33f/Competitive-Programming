#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	vector<int> summd(n+1);
	summd[0] = 0;
	int sum = 0;
	for (int q = 0; q < n; q++)
	{
		sum = (sum + a[q])%x;
		summd[q+1] = sum; 
	}
	int longest = -1;
	int left = 0;
	while (left <= n && summd[left] == summd[n])
	{
		left++;
	}
	if (left == n+1)
	{
		cout << "-1\n";
		return;
	}
	longest = max(longest, n-left);
	int right = n;
	while (right >= 0 && summd[right] == summd[0])
	{
		right--;
	}
	longest = max(longest, right);
	cout << longest << "\n";
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

