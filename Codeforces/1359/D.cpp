#include <bits/stdc++.h>
using namespace std;
const int inf = -100000000;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<int> cards(n);
	bool posfound = false;
	for (int q = 0; q < n; q++)
	{
		cin >> cards[q];
		if (cards[q] > 0)
		{
			posfound = true;
		}
	}
	if (!posfound)
	{
		cout << "0\n";
		return 0;
	}
	int ldp[n+1][61];
	for (int q = 0; q < n; q++)
	{
		if (q == 0)
		{
			for (int w = -30; w <= 30; w++)
			{
				if (cards[q] > w)
				{
					ldp[q][w+30] = inf;
				}
				else
				{
					ldp[q][w+30] = cards[q];
				}
			}
		}
		else
		{
			for (int w = -30; w <= 30; w++)
			{
				if (cards[q] > w)
				{
					ldp[q][w+30] = inf;
				}
				else
				{
					ldp[q][w+30] = cards[q] + max(0, ldp[q-1][w+30]);
				}
			}
		}
	}
	ll best = inf;
	for (int q = 0; q < n; q++)
	{
		for (ll w = -30; w <= 30; w++)
		{
			if (ldp[q][w+30] != inf)
			{
				best = max(best, ldp[q][w+30] - w);
			}
		}
	}
	cout << best << "\n";
	return 0;
}
