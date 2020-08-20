#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<pair<ll,ll>> coords;
	ll cur = 1;
	coords.emplace_back(0,0);
	coords.emplace_back(0,1);
	coords.emplace_back(1,0);
	coords.emplace_back(1,1);
	while (cur <=  n)
	{
		coords.emplace_back(cur+1,cur+1);
		coords.emplace_back(cur+1,cur);
		coords.emplace_back(cur,cur+1);
		cur++;
	}
	cout << coords.size() << "\n";
	int sz = coords.size();
	for (int q = 0; q < sz; q++)
	{
		cout << coords[q].first << " " << coords[q].second << "\n";
	}
	return 0;
}

