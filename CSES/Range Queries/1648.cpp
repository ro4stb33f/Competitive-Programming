#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll bit_get(vector<ll>&bit, int index)
{
	ll res = 0;
	while (index >= 1)
	{
		res += bit[index];
		index -= (index & -index);
	}
	return res;
}

void bit_update(vector<ll> &bit, int index, ll inc)
{
	while (index <= n)
	{
		bit[index] += inc;
		index += (index & -index);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	vector<ll> nums(n+1);
	vector<ll> fenwick(n+1);
	for (int w = 1; w <= n; w++)
	{
		ll a;
		cin >> a;
		nums[w] = a;
		bit_update(fenwick, w, a);
	}
	for (int w = 0; w < q; w++)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			bit_update(fenwick, b, c-nums[b]);
			nums[b]=c;
		}
		else
		{
			cout << bit_get(fenwick, c) - bit_get(fenwick, b-1) << "\n";
		}
	}
	return 0;
}
