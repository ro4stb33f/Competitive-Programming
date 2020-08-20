#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
ll pow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	ll ret = pow(a,b/2);
	ret = (ret * ret)%md;
	if (b % 2 == 1)
	{
		ret = (ret * a) % md;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll x,y;
		cin >> x >> y;
		cout << pow(x,y) << "\n";
	}
	return 0;
}

