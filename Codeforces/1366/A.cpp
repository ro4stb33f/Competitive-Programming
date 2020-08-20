#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll a,b;
	cin >> a >> b;
	if (a > b)
	{
		swap(a,b);
	}
	if (2 * a <= b)
	{
		cout << a << "\n";
		return;
	}
	ll c = 2 * a - b;
	ll amt;
	if (c % 3 == 0)
	{
		amt = c/3;
	}
	else
	{
		amt = c/3+1;
	}
	cout << (a-amt) << "\n";
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
