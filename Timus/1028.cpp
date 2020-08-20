#include <bits/stdc++.h>
using namespace std;
const int mx = 32001;
vector<int> bit(mx+2);
void add(int i, int val)
{
	while (i <= mx)
	{
		bit[i]+=val;
		i+=(i&-i);
	}
}
int get(int i)
{
	int tot = 0;
	while (i >= 1)
	{
		tot+=bit[i];
		i-=(i&-i);
	}
	return tot;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int x,y;
	vector<int> amt(n);
	for (int q = 0; q < n; q++)
	{
		cin >> x >> y;
		int z = get(x+1);
		amt[z]++;
		add(x+1,1);
	}
	for (int q = 0; q < n; q++)
	{
		cout << amt[q] << "\n";
	}
	return 0;
}
