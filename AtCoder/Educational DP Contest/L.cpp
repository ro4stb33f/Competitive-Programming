#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n+1);
	vector<ll> pref(n+1);
	for (int q = 1; q <= n; q++)
	{
		cin >> a[q];
		pref[q] = pref[q-1] + a[q];
	}
	ll dp[n+1][n+1];
	for (int q = 1; q <= n; q++)
	{
		dp[q][q] = a[q];
	}
	for (int q = 2; q <= n; q++)
	{
		for (int w = 1; w+q-1<= n; w++)
		{
			dp[w][w+q-1] = max(a[w] + pref[w+q-1] - pref[w] - dp[w+1][w+q-1], a[w+q-1] + pref[w+q-2] - pref[w-1] - dp[w][w+q-2]);
		}
	}
	cout << (2 * dp[1][n] - pref[n]) << "\n";
	return 0;
}
