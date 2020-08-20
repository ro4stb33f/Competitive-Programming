#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve()
{
	string s;
	cin >> s;
	int len = s.size();
	vector<int> lzero;
	vector<int> lone;
	vector<int> rzero(len+2);
	vector<int> rone(len+2);
	lzero.push_back(0);
	lone.push_back(0);
	for (int q = 0; q < len; q++)
	{
		if (s[q] == '0')
		{
			lzero.push_back(lzero[q]);
			lone.push_back(lone[q]+1);
		}
		else
		{
			lzero.push_back(lzero[q]+1);
			lone.push_back(lone[q]);
		}
	}
	for (int q = len; q >= 1; q--)
	{
		if (s[q-1] == '0')
		{
			rzero[q] = rzero[q+1];
			rone[q] = rone[q+1]+1;
		}
		else
		{
			rzero[q] = rzero[q+1]+1;
			rone[q] = rone[q+1];
		}
	}
	int minn = INT_MAX;
	for (int q = 0; q <= len; q++)
	{
		minn = min(minn, lzero[q] + rone[q+1]);
		minn = min(minn, lone[q] + rzero[q+1]);
	}
	cout << minn << "\n";
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
