#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
int main()
{
	ll n;
	cin >> n;
	if (n <= 2)
	{
		cout << n-1 << "\n";
	}
	else
	{
		vector<ll> rec(n+1);
		rec[1] = 0;
		rec[2] = 1;
		for (ll q = 3; q <= n; q++)
		{
			rec[q] = ((q-1) * ((rec[q-1] + rec[q-2]) % md)) % md;
		}
		cout << rec[n] << "\n";
	}
	return 0;
}
