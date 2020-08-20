#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	bool dp[k+1];
	for (int q = 0; q <= k; q++)
	{
		dp[q] = false;
		for (int w = 0; w < n && q-a[w] >= 0; w++)
		{
			if (!dp[q-a[w]])
			{
				dp[q] = true;
				break;
			}
		}
	}
	if (dp[k])
	{
		cout << "First\n";
	}
	else
	{
		cout << "Second\n";
	}
	return 0;
}
