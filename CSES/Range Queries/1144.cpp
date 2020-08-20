#include <bits/stdc++.h>
using namespace std;
int n;
int sz;
const int mx = 600005;
vector<int> bit(mx);

void update(int i, int inc)
{
	while (i <= sz)
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
		res += bit[i];
		i-=(i & -i);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> n >> q;
	map<int, int> compress;
	vector<int> possalaries;
	vector<tuple<int, int, int>> queries;
	vector<int> cursals(n+1);
	for (int w = 1; w <= n; w++)
	{
		cin >> cursals[w];
		possalaries.push_back(cursals[w]);
	}
	for (int w = 1; w <= q; w++)
	{
		char c;
		cin >> c;
		int a,b;
		cin >> a >>b;
		if (c == '!')
		{
			queries.push_back(make_tuple(1,a,b));
			possalaries.push_back(b);
		}
		else
		{
			queries.push_back(make_tuple(2, a,b));
			possalaries.push_back(a);
			possalaries.push_back(b);
		}
	}
	sort(possalaries.begin(), possalaries.end());
	possalaries.erase(unique(possalaries.begin(), possalaries.end()), possalaries.end());
	sz = possalaries.size();
	for (int w = 0; w < sz; w++)
	{
		compress[possalaries[w]] = w+1;
	}
	vector<int> bit(sz+1);
	for (int w = 1; w <= n; w++)
	{
		update(compress[cursals[w]], 1);
	}
	for (int w = 0; w < q; w++)
	{
		int t,x,y;
		tie(t,x,y) = queries[w]; 
		if (t == 1)
		{
			update(compress[cursals[x]], -1);
			update(compress[y], 1);
			cursals[x] = y;
		}
		else
		{
			cout << (get(compress[y]) - get(compress[x]-1)) << "\n";
		}
	}
	return 0;
}
