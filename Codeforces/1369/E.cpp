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
	int n,m;
	cin >> n >> m;
	vector<int> amt(n+1);
	for (int q = 1; q <= n; q++)
	{
		cin >> amt[q];
	}
	vector<pair<int,int>> adj[n+1];
	for (int q = 1; q <= m; q++)
	{
		int a,b;
		cin >> a >> b;
		amt[a]--;
		amt[b]--;
		adj[a].emplace_back(b,q);
		adj[b].emplace_back(a,q);
	}
	set<pair<int,int>> s;
	for (int q = 1; q <= n; q++)
	{
		s.insert({amt[q], q});
	}
	bool bad = false;
	vector<bool> used(m+1);
	vector<int> ans;
	while (s.size() > 0)
	{
		auto it = s.rbegin();
		if (it->first < 0)
		{
			bad = true;
			break;
		}
		int idx = it->second;
		for (auto a : adj[idx])
		{
			if (used[a.second])
			{
				continue;
			}
			used[a.second] = true;
			s.erase({amt[a.first], a.first});
			s.insert({amt[a.first]+1, a.first});
			amt[a.first]++;
			ans.push_back(a.second);
		}
		s.erase(s.find({amt[idx], idx}));
	}
	if (bad)
	{
		cout << "DEAD\n";
		return 0;
	}
	cout << "ALIVE\n";
	reverse(ans.begin(), ans.end());
	for (int q : ans)
	{
		cout << q << " ";
	}
	cout << "\n";
	return 0;
}

