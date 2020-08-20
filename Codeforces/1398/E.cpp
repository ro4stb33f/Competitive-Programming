#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> fire;
set<ll> lightning;
set<ll> largest;
ll firesum = 0, lightningsum = 0, largestsum = 0;

void addtolargest()
{
	if (largest.size() == 0)
	{
		ll best = -1;
		if (fire.size() > 0)
		{
			best = max(best, *fire.rbegin());
		}
		if (lightning.size() > 0)
		{
			best = max(best, *lightning.rbegin());
		}
		largestsum += best;
		largest.insert(best);
		return;
	}
	auto it1 = fire.lower_bound(*largest.begin());
	auto it2 = lightning.lower_bound(*largest.begin());
	if (it1 != fire.begin())
	{
		it1--;
		if (it2 != lightning.begin())
		{
			it2--;
			largest.insert(max(*it1, *it2));
			largestsum += max(*it1, *it2);
		}
		else
		{
			largest.insert(*it1);
			largestsum += *it1;
		}
	}
	else if (it2 != lightning.begin())
	{
		it2--;
		largest.insert(*it2);
		largestsum += *it2;
	}
}

void removefire(ll x)
{
	fire.erase(x);
	firesum-= x;
	if (largest.find(x) != largest.end())
	{
		largestsum -= x;
		largest.erase(x);
		addtolargest();
	}
}

void addfire(ll x)
{
	fire.insert(x);
	firesum += x;
	if (largest.size() > 0 && x > *largest.begin())
	{
		largestsum -= *largest.begin();
		largestsum += x;
		largest.erase(largest.begin());
		largest.insert(x);
	}
}

void addlight(ll x)
{
	lightning.insert(x);
	lightningsum += x;
	if (largest.size() > 0 && x > *largest.begin())
	{
		largest.insert(x);
		largestsum += x;
	}
	else
	{
		addtolargest();	
	}
}

void removelight(ll x)
{
	lightning.erase(x);
	lightningsum -= x;
	if (x > *largest.begin())
	{
		largest.erase(x);
		largestsum -= x;
	}
	else
	{
		largestsum -= *largest.begin();
		largest.erase(largest.begin());
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int t;
	ll d;
	for (int q = 0; q < n; q++)
	{
		cin >> t >> d;
		if (t == 0)
		{
			if (d < 0)
			{
				removefire(-d);
			}
			else
			{
				addfire(d);
			}
		}
		else
		{
			if (d < 0)
			{
				removelight(-d);
			}
			else
			{
				addlight(d);
			}
		}
		ll ans = lightningsum + firesum;
		if (ans == 0)
		{
			cout << ans << "\n";
			continue;
		}
		if (fire.size() == 0)
		{
			ans += lightningsum - *lightning.begin();
		}
		else
		{
			if (lightning.size() != 0)
			{
				if (*fire.rbegin() < *lightning.begin())
				{
					ans += lightningsum - *lightning.begin() + *fire.rbegin();
				}
				else
				{
					ans += largestsum;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
