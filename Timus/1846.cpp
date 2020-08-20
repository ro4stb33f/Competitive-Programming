#include <bits/stdc++.h>
using namespace std;
int mx;
int gcd(int a, int b)
{
	return (a == 0 ? b : gcd(b%a, a));
}
vector<int> st(2e5+3);
void add(int i, int val)
{
	i += mx;
	st[i] = val;
	for (int q = i/2; q >= 1; q>>=1)
	{
		st[q] = gcd(st[2*q], st[2*q+1]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	mx = t;
	map<int, vector<int>> place;
	vector<int> pos(t);
	for (int q = 0; q < t; q++)
	{
		pos[q] = q;
	}
	char c;
	int n;
	while (t--)
	{
		cin >> c >> n;
		if (c == '+')
		{
			int p = pos.back();
			pos.pop_back();
			place[n].push_back(p);
			add(p, n);
		}
		else
		{
			int x = place[n].back();
			place[n].pop_back();
			pos.push_back(x);
			add(x,0);
		}
		cout << max(st[1], 1) << "\n";
	}
	return 0;
}
