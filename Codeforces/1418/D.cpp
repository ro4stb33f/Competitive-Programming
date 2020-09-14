#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> vals;
multiset<ll> diff;
void add(ll x)
{
	vals.insert(x);
	auto it = vals.find(x);
	ll below = -1, above = LLONG_MAX;
	if (it != vals.begin())
	{
		auto it2 = it;
		it2--;
		below = *it2;
	}
	it++;
	if (it != vals.end())
	{
		above = *it;
	}
	if (below != -1) diff.insert(x - below);
	if (above != LLONG_MAX) diff.insert(above - x);
	if (below != -1 && above != LLONG_MAX) diff.erase(diff.find(above - below));
}

void rem(ll x)
{
	auto it = vals.find(x);
	ll below = -1, above = LLONG_MAX;
	if (it != vals.begin())
	{
		auto it2 = it;
		it2--;
		below = *it2;
	}
	it++;
	if (it!= vals.end())
	{
		above = *it;
	}
	if (below != -1) diff.erase(diff.find(x - below));
	if (above != LLONG_MAX) diff.erase(diff.find(above - x));
	if (below != -1 && above != LLONG_MAX) diff.insert(above - below);
	vals.erase(x);
}

ll get()
{
	if ((int)vals.size() <= 2) return 0;
	assert((int)diff.size() > 0);
	return *vals.rbegin() - *vals.begin() - *diff.rbegin();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,qq;
	cin >> n >> qq;
	for (int q = 0; q < n; q++)
	{
		ll a;
		cin >> a;
		add(a);
	}
	cout << get() << "\n";
	for (int q = 0; q < qq; q++)
	{
		ll t,x;
		cin >> t >> x;
		if (t) add(x);
		else rem(x);
		cout << get() << "\n";
	}
	return 0;
}
