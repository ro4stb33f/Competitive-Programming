#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 998244353;

ll mul(ll a, ll b)
{
	return (((a * b) % md) + md) %md;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
	}
	vector<int> b(m);
	for (int q = 0; q < m; q++)
	{
		cin >> b[q];
	}
	map<int,int> ma;
	for (int q = 0; q < n; q++)
	{
		ma[a[q]] = q;
	}
	if (b[0] != ma.begin()->first)
	{
		cout << "0\n";
		return 0;
	}
	auto it = ma.begin();
	int prevdivide = -1;
	ll ans = 1;
	for (int q = 1; q < m; q++)
	{
		int highest = prevdivide;
		while (it->first != b[q])
		{
			highest = max(highest, it->second);
			it++;
			if (it == ma.end())
			{
				cout << "0\n";
				return 0;
			}
		}
		if (highest > ma[b[q]] || ma[b[q]] < prevdivide)
		{
			cout << "0\n";
			return 0;
		}
		ans = mul(ans, (ma[b[q]]-highest));
		prevdivide = highest;
	}
	cout << ans << "\n";
	return 0;
}
