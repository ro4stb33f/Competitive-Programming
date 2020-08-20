#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int q = 0; q < n; q++)
	{
		cin >> numbers[q];
	}
	sort(numbers.begin(), numbers.end());
	for (int q = 1; q < 2048; q++)
	{
		vector<int> xorednums;
		for (int w = 0; w < n; w++)
		{
			xorednums.push_back((numbers[w] ^ q));
		}
		sort(xorednums.begin(), xorednums.end());
		bool good = true;
		for (int w = 0; w < n; w++)
		{
			if (numbers[w] != xorednums[w])
			{
				good = false;
				break;
			}
		}
		if (good == true)
		{
			cout << q << "\n";
			return;
		}
	}
	cout << "-1\n";
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
