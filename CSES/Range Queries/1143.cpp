#include <bits/stdc++.h>
using namespace std;
int n;

int get(vector<int>&seg, int l, int r)
{
	int res = -1;
	l+=n;
	r+=n;
	while (l <= r)
	{
		if (l%2 == 1)
		{
			res = max(res, seg[l++]);
		}
		if (r%2 == 0)
		{
			res = max(res, seg[r--]);
		}
		l/=2;
		r/=2;
	}
	return res;
}
void update(vector<int>&seg, int i, int inc)
{
	i+=n;
	seg[i] += inc;
	for (int q = i/2; q >= 1; q/=2)
	{
		seg[q] = max(seg[2*q], seg[2*q+1]);
	}
}

int main()
{
	int m;
	cin >> n >> m;
	vector<int> seg(2*n);
	for (int q = 0; q < n; q++)
	{
		cin >> seg[q+n];
	}
	for (int q = n-1; q >= 1; q--)
	{
		seg[q] = max(seg[2*q], seg[2*q+1]);
	}
	vector<int> results(m);
	for (int q = 0; q < m; q++)
	{
		int a;
		cin >> a;
		int index = -1;
		for (int w = n; w >= 1; w /=2)
		{
			while (index + w < n)
			{
				if (get(seg, 0, index+w) < a)
				{
					index += w;
				}
				else
				{
					break;
				}
			}
		} 
		if (index == n-1)
		{
			results[q] = 0;
		}
		else
		{
			index++;
			update(seg, index, -a);
			results[q] = index+1;
		}
	}
	cout << results[0];
	for (int q = 1; q < m; q++)
	{
		cout << " " << results[q];
	}
	return 0;
}
