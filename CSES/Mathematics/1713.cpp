#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> sieve(mx+1);
	for (int q = 2; q <= mx; q++)
	{
		for (int w = 1; q * w <= mx; w++)
		{
			if (sieve[q*w] == 0)
			{
				sieve[q*w] = q;
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			cout << "1\n";
			continue;
		}
		map<int,int> ct;
		while (x > 1)
		{
			ct[sieve[x]]++;
			x/=sieve[x];
		}
		int tot = 1;
		auto it = ct.begin();
		while (it != ct.end())
		{
			tot *= (it->second + 1);
			it++;
		}
		cout << tot << "\n";
	}
	return 0;
}
