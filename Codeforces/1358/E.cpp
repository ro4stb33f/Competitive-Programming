#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int half;
	if (n % 2 == 1)
	{
		half = n/2 + 1;
	}
	else
	{
		half = n/2;
	}
	vector<ll> nums(half);
	for (int q = 0; q < half; q++)
	{
		cin >> nums[q];
	}
	ll endnum;
	cin >> endnum;
	if (n == 2)
	{
		if (nums[0] + endnum > 0)
		{
			cout << "2\n";
			return 0;
		}
	}
	vector<ll> prefix(n+1);
	for (int q = 1; q <= half; q++)
	{
		prefix[q] = prefix[q-1] + nums[q-1];
	}
	vector<ll> prefixminus(n+1);
	for (int q = 1; q <= half; q++)
	{
		prefixminus[q] = prefix[q] - q * endnum;
	}
	multiset<ll> curprefixminus;
	int actualhalf = n/2;
	if (n % 2 == 0)
	{
		actualhalf--;
	}
	for (int q = 1; q <= actualhalf; q++)
	{
		curprefixminus.insert(prefixminus[q]);
	}
	int st;
	ll initial;
	if (n % 2)
	{
		st = half;
		initial = prefix[half];
	}
	else
	{
		st = half + 1;
		initial = prefix[half] + endnum;
	}
	for (int q = st; q <= n; q++)
	{
		ll temp = initial + (q - st) * endnum;
		if (temp <= 0)
		{
			continue;
		}
		if (q == n)
		{
			cout << q << "\n";
			return
		}
		if (curprefixminus.size() > 0)
		{
			auto it = curprefixminus.end();
			it--;
			if (temp - *it > 0)
			{
				cout << q <<"\n";
				return 0;
			}
		}
		if (q < n)
		{
			curprefixminus.erase(curprefixminus.find(prefixminus[n-q]));
		}
	}
	cout << "-1\n";
	return 0;
}
