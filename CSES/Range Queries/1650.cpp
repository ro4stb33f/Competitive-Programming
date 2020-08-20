#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	int prefix[n+1];
	prefix[0] = 0;
	for (int w = 1; w <= n; w++)
	{
		cin >> prefix[w];
		prefix[w] ^= prefix[w-1];
	}
	for (int w = 0; w < q; w++)
	{
		int a,b;
		cin >> a >> b;
		cout << (prefix[a-1]^prefix[b]) << "\n";
	}
	return 0;
}
