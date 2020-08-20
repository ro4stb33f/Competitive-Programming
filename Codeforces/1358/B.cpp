#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	vector<int> nums;
	for (int q = 0; q < n; q++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());
	for (int q = n-1; q >= 0; q--)
	{
		if (nums[q] <= q+1)
		{
			cout << q+2 << "\n";
			return;
		}
	}
	cout << "1\n";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
