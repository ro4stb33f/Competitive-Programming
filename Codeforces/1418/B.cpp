#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n+1);
	for (int q = 1; q<= n; q++) cin >> a[q];
	vector<ll> unlocked(n+1);
	for (int q = 1; q <= n; q++) cin >> unlocked[q];
	ll usum = 0;
	vector<ll> psum(n+1);
	vector<ll> vals;
	for (int q = 1; q <= n; q++)
	{
		if (unlocked[q] == 1) psum[q] = psum[q-1] + a[q];
		else
		{
			psum[q] = psum[q-1];
			vals.push_back(a[q]);
			usum += a[q];
		}
	}
	int sz = vals.size();
	vector<bool> used(sz);
	vector<ll> newa(n+1);
	for (int q = n; q >= 1; q--)
	{
		if (unlocked[q] == 1)
		{
			newa[q] = a[q];
			continue;
		}
		ll idx = -1, val = LLONG_MAX, nonused = -1;
		for (int w = 0; w < sz; w++)
		{
			if (used[w]) continue;
			nonused = w;
			if (psum[q] + usum - vals[w] >=0 && vals[w] < val)
			{
				idx = w;
				val = vals[w];
			}
		}
		if (idx == -1)
		{
			newa[q] = vals[nonused];
			used[nonused] = true;
			usum -= vals[nonused];
		}
		else
		{
			newa[q] = vals[idx];
			used[idx] = true;
			usum -= vals[idx];
		}
	}
	for (int q = 1; q <= n; q++) cout << newa[q] << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
