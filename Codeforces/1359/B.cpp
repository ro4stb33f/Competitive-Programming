#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll n,m,x,y;
	cin >> n >> m >> x >> y;
	y = min(y, 2 * x);
	ll totcost = 0;
	for (int q = 0; q < n; q++)
	{
		string s;
		cin >> s;
		vector<ll> spots;
		ll cur = 0;
		for (int w = 0; w < m; w++)
		{
			if (s[w] == '.')
			{
				cur++;
			}
			else
			{
				if (cur > 0)
				{
					spots.push_back(cur);
					cur = 0;
				}
			}
		}
		if (cur > 0)
		{
			spots.push_back(cur);
		}
		for (int w = 0; w < spots.size(); w++)
		{
			if (spots[w] % 2 == 1)
			{
				totcost += (x + (y * (spots[w]-1)/2));
			}
			else
			{
				totcost += (y * spots[w]/2);
			}
		}
	}
	cout << totcost << "\n";
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
