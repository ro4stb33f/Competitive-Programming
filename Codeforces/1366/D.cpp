#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> sieve(1e7+1, -1);
	for (int q = 2; q <= 1e7; q++)
	{
		if (sieve[q] != -1)
		{
			continue;
		}
		for (ll u = 1; u * q <= 1e7; u++)
		{
			if (sieve[u * q] == -1)
			{
				sieve[u * q] = q;
			}
		}
	}
	int n;
	cin >> n;
	vector<ll> left;
	vector<ll> right;
	for (int q = 0; q < n; q++)
	{
		ll a;
		cin >> a;
		ll acpy = a;
		ll initial = -1;
		vector<int> pfactors;
		while (a > 1)
		{
			pfactors.push_back(sieve[a]);
			a /= sieve[a];
		}
		ll smallest = pfactors[0];
		bool finished = false;
		int n = 0;
		ll num = 1;
		while (n < pfactors.size())
		{
			if (pfactors[n] != smallest)
			{
				finished = true;
				break;
			}
			else
			{
				num *= pfactors[n];
			}
			n++;
		}
		if (finished == false)
		{
			left.push_back(-1);
			right.push_back(-1);
		}
		else
		{
			left.push_back(num);
			right.push_back(acpy/num);
		}
	}
	for (int q = 0; q < left.size(); q++)
	{
		cout << left[q] << " ";
	}
	cout << "\n";
	for (int q = 0; q < right.size(); q++)
	{
		cout << right[q] << " ";
	}
	cout << "\n";
	return 0;
}
