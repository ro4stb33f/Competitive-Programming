#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;

int main()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	ll dp[n][k+1];
	for (int q = 0; q <= a[0]; q++)
	{
		dp[0][q] = 1;
	}
	for (int q = a[0]+1; q <= k; q++)
	{
		dp[0][q] = 0;
	}
	for (int q = 1; q < n; q++)
	{
		dp[q][0] = 1;
		for (int w = 1; w <= a[q]; w++)
		{
			dp[q][w] = (dp[q-1][w] + dp[q][w-1]) % md;
		}
		for (int w = a[q]+1; w <= k; w++)
		{
			dp[q][w] = (dp[q][w-1] + dp[q-1][w] - dp[q-1][w - a[q]-1]) % md;
		}
	}
	cout << (dp[n-1][k] + md) % md << "\n";
	return 0;
}
