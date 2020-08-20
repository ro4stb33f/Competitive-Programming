#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	int n;
	string s;
	cin >> n >> s;
	map<int,ll> mp;
	mp[0] = 1;
	int cur = 0;
	for (int q = 0; q < n; q++)
	{
		int val = (s[q]-'0') - 1;
		cur+=val;
		mp[cur]++;
	}
	int tot = 0;
	auto it = mp.begin();
	while (it != mp.end())
	{
		tot += it->second * (it->second - 1) / 2; 
		it++;
	}
	cout << tot << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
