#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool better(ll h, ll c, ll t, ll x, ll y)
{
	if (abs((h+c) * x + h - t * (2 * x + 1)) * (2 * y + 1) < abs((h+c) * y + h - t * (2 * y + 1)) * (2 * x + 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void solve()
{
	ll h, c, t;
	cin >> h >> c >> t;
	if (t == h)
	{
		cout << "1\n";
		return;
	}
	if (2 * t <= h + c)
	{
		cout << "2\n";
		return;
	}
	ll mid = (h-t)/(2 * t - h - c);
	ll curbest = max(mid-1, 0LL);
	if (better(h,c,t,mid,curbest))
	{
		curbest = mid;
	}
	if (better(h,c,t,mid+1,curbest))
	{
		curbest = mid+1;
	}
	cout << (2 * curbest + 1) << "\n";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
