#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
vector<int> bit(mx+1);

void update(int i, int inc)
{
	while (i <= mx)
	{
		bit[i] += inc;
		i += (i & -i);
	}
}

int getb(int i)
{
	int tot = 0;
	while (i >= 1)
	{
		tot += bit[i];
		i -= (i & -i);
	}
	return tot;
}

int main()
{
	int n,q;
	cin >> n >> q;
	vector<int> nums(n+1);
	set<int> sorted;
	for (int w = 1; w <= n; w++)
	{
		cin >> nums[w];
		sorted.insert(nums[w]);
	}
	auto it = sorted.begin();
	map<int,int> ma;
	int ct = 1;
	while (it != sorted.end())
	{
		ma[*it] = ct++;
		it++;
	}
	vector<tuple<int,int,int>> queries;
	for (int w = 0; w < q; w++)
	{
		int a,b;
		cin >> a >> b;
		queries.emplace_back(a,b, w);
	}
	sort(queries.begin(), queries.end(), [](tuple<int,int,int> a, tuple<int,int,int> b){
			if (get<1>(a) == get<1>(b))
			{return get<0>(a) < get<0>(b);}
			return get<1>(a) < get<1>(b);});
	vector<int> ans(q);
	vector<int> last(mx+1, -1);
	int qcount = 0;
	for (int w = 1; w <= n; w++)
	{
		int ind = ma[nums[w]];
		int l = last[ind];
		if (l != -1)
		{
			update(l, -1);
		}
		update(w,1);
		last[ind] = w;
		while (qcount < q && get<1>(queries[qcount]) == w)
		{
			ans[get<2>(queries[qcount])] = getb(w) - getb(get<0>(queries[qcount]) - 1);
			qcount++;
		}
	}
	for (int w = 0; w < q; w++)
	{
		cout << ans[w] << "\n";
	}
	return 0;
}
