#include <bits/stdc++.h>
using namespace std;
int n;
void update(vector<int>&seg, int i, int val)
{
	i+=n;
	seg[i] = val;
	for (int q = i/2; q >= 1; q/=2)
	{
		seg[q] = min(seg[2*q], seg[2*q+1]);
	}
}

int get(vector<int>&seg, int a, int b)
{
	a += n;
	b += n;
	int res = INT_MAX;
	while (a <= b)
	{
		if (a%2 == 1)
		{
			res = min(res, seg[a++]);
		}
		if (b % 2 == 0)
		{
			res = min(res, seg[b--]);
		}
		a/=2;
		b/=2;
	}
	return res;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	vector<int> segtree(2 * n + 1);
	for (int w = 0; w < n; w++)
	{
		cin >> segtree[w+n];
	}
	for (int w = n-1; w >= 1; w--)
	{
		segtree[w] = min(segtree[2*w], segtree[2*w+1]);
	}
	for (int w = 0; w < q; w++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(segtree, b-1, c);
		}
		else
		{
			cout << get(segtree, b-1, c-1) << "\n";
		}
	}
	return 0;
}
