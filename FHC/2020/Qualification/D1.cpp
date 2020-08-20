#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e6;
const ll inf = 1e17;
vector<ll> st(2*mx+10);
int n;

void reset()
{
	for (int q = 2*n+5; q >= 1; q--)
	{
		st[q] = inf;
	}
}

void update(int i, ll val)
{
	i += n;
	st[i] = val;
	i /=2;
	while (i >= 1)
	{
		st[i] = min(st[2*i], st[2*i+1]);
		i /=2;
	}
}

ll get(int a, int b)
{
	ll ret = inf;
	a += n;
	b += n;
	while (a <= b)
	{
		if (a % 2 == 1)
		{
			ret = min(ret, st[a]);
			a++;
		}
		if (b % 2 == 0)
		{
			ret = min(ret, st[b]);
			b--;
		}
		a /=2;
		b /=2;
	}
	return ret;
}

ll getsingle(int i)
{
	return st[i+n];
}

void solve()
{
	int m;
	cin >> n >> m;
	reset();
	vector<ll> val(n+1);
	for (int q = 1; q <= n; q++)
	{
		cin >> val[q];
	}
	if (m == n-1)
	{
		cout << "0\n";
		return;
	}
	update(1,0);
	for (int q = 2; q <= n; q++)
	{
		int lbound = max(1,q-m);
		int rbound = q-1;
		if (val[q] != 0 || q == n)
		{
			ll pos = get(lbound, rbound);
			if (pos != inf)
			{
				update(q, pos+val[q]);
			}
		}
	}
	ll x = getsingle(n);
	if (x == inf)
	{
		cout << "-1\n";
	}
	else
	{
		cout << x-val[n] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
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
