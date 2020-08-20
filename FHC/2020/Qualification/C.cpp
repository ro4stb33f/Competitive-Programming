#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	vector<pair<ll,ll>> trees;
	for (int q = 0; q < n; q++)
	{
		ll a,b;
		cin >> a >> b;
		trees.emplace_back(a,b);
	}
	sort(trees.begin(), trees.end());
	map<ll,ll> left;
	map<ll,ll> right;
	ll ans = 0;
	for (int q = 0; q < n; q++)
	{
		auto it = left.find(trees[q].first);
		ll len = 0;
		if (it != left.end())
		{
			len = it->second;
		}
		ll val = len+trees[q].second;
		ans = max(ans, val);
		auto it1 = left.find(trees[q].first+trees[q].second);
		if (it1 == left.end() || val > it1->second)
		{
			left[trees[q].first+trees[q].second] = val;
		}
	}
	for (int q = n-1; q >= 0; q--)
	{
		auto it = right.find(trees[q].first);
		ll len = 0;
		if (it != right.end())
		{
			len = it->second;
		}
		ll val = len+trees[q].second;
		ans = max(ans, val);
		auto it1 = right.find(trees[q].first-trees[q].second);
		if (it1 == right.end() || val > it1->second)
		{
			right[trees[q].first - trees[q].second] = val;
		}
		auto it2 = left.find(trees[q].first-trees[q].second);
		if (it2 != left.end())
		{
			ans = max(ans, val+it2->second);
		}
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("timber_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ": ";
		solve();
	}
	return 0;
}
