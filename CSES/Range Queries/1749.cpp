#include <bits/stdc++.h>
using namespace std;
const int mx = 200005;
vector<int> bit(mx);
int n;
void update(int i, int inc)
{
	while (i <= n)
	{
		bit[i]+=inc;
		i+=(i & -i);
	}
}

int get(int i)
{
	int res = 0;
	while (i >= 1)
	{
		res+=bit[i];
		i-=(i & -i);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> vals(n+1);
	for (int q = 1; q <= n; q++)
	{
		cin >> vals[q];
		update(q, 1);
	}
	for (int q = 1; q <= n; q++)
	{
		int a;
		cin >> a;
		int index = 0;
		for (int w = n; w >= 1; w /=2)
		{
			while (index + w <= n)
			{
				if (get(index+w) < a)
				{
					index+=w;
				}
				else
				{
					break;
				}
			}
		}
		cout << vals[index+1] << " ";
		update(index+1, -1);
	}
	return 0;
}
