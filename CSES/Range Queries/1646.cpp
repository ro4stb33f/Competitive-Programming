#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,q;
	cin >> n >> q;
	vector<ll> prefix(n+1);
	for (int w = 1; w <= n; w++)
	{
		ll a;
		cin >> a;
		prefix[w] = prefix[w-1] + a;
	}
	for (int w = 1; w <= q; w++)
	{
		int a,b;
		cin >> a >> b;
		cout << prefix[b]-prefix[a-1] << "\n";
	}
	return 0;
}
