#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll md = 1e9+7;

int main()
{
	string s;
	ll d;
	cin >> s >> d;
	int n = s.length();
	ll dp[n][d];
	dp[0][0] = 1;
	for (int q = 1; q < d; q++)
	{
		dp[0][q] = 0;
	}
	for (int q = 1; q < n; q++)
	{
		for (int w = 0; w < d; w++)
		{
			dp[q][w] = 0;
			for (int e = 0; e < 10; e++)
			{
				dp[q][w] = (dp[q][w] + dp[q-1][(((w-e) % d) + d) % d]) % md;
			}
		}
	}
	ll tot = 0;
	ll dsum = 0;
	for (int q = 0; q < n; q++)
	{
		int digit = s[q] - '0';
		for (int w = 0; w < digit; w++)
		{
			tot = (tot + dp[n-q-1][(((-dsum-w) % d) + d) % d]) % md;
		}
		dsum = (dsum + digit) % md;
	}
	if (dsum % d == 0)
	{
		tot = (tot + 1) % md;
	}
	cout << (tot+md-1) % md << "\n";
	return 0;
}
