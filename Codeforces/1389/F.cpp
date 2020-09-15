#include <bits/stdc++.h>
using namespace std;
 
struct node
{
	int mx;
	int lazy;
};
struct segtree{
	int n;
	vector<node> v;
	segtree(int _n) : n(_n)
	{
		v.resize(4*n+5);
	}
	void push(int k, int l, int r)
	{
		v[k].mx += v[k].lazy;
		if (l != r) for (int q = 0; q < 2; q++) v[2*k+q].lazy += v[k].lazy;
		v[k].lazy = 0;
	}
	void pull(int k)
	{
		v[k].mx = max(v[2*k].mx, v[2*k+1].mx);
	}
	void update(int a, int b, int inc, int k, int l, int r)
	{
		push(k,l,r);
		if (r < a || l > b) return;
		if (a <= l && r <= b)
		{
			v[k].lazy += inc;
			push(k,l,r);
			return;
		}
		int m = (l+r)/2;
		update(a,b,inc,2*k,l,m);
		update(a,b,inc,2*k+1,m+1,r);
		pull(k);
	}
	int get(int a, int b, int k, int l, int r)
	{
		push(k,l,r);
		if (r < a || l > b) return INT_MIN;
		if (a <= l && r <= b) return v[k].mx;
		int m = (l+r)/2;
		return max(get(a,b,2*k,l,m), get(a,b,2*k+1,m+1,r));
	}
};
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> segs(2);
	for (int q = 0; q < 2; q++) segs[q].emplace_back(-1,-1);
	for (int q = 0; q < n; q++)
	{
		int l,r,t;
		cin >> l >> r >> t;
		t--;
		segs[t].emplace_back(r,l);
	}
	for (int q = 0; q < 2; q++) sort(segs[q].begin(), segs[q].end());
	segtree zero(segs[0].size());
	segtree one(segs[1].size());
	int ans = 0, x = 1, y = 1, s1 = segs[0].size(), s2 = segs[1].size();
	while (x < s1 || y < s2)
	{
		bool dox = true;
		if (x >= s1) dox = false;
		if (x < s1 && y < s2 && segs[0][x].first > segs[1][y].first) dox = false;
		if (dox)
		{
			int idx = lower_bound(segs[1].begin(), segs[1].end(), make_pair(segs[0][x].second, -1)) - segs[1].begin();
			idx--;
			int z = 1+one.get(0,idx,1,0,s2-1);
			ans = max(ans, z);
			one.update(0,idx,1,1,0,s2-1);
			zero.update(x,x,z,1,0,s1-1);
			x++;
		}
		else
		{
			int idx = lower_bound(segs[0].begin(), segs[0].end(), make_pair(segs[1][y].second, -1)) - segs[0].begin();
			idx--;
			int z = 1+zero.get(0,idx,1,0,s1-1);
			ans = max(ans, z);
			zero.update(0,idx,1,1,0,s1-1);
			one.update(y,y,z,1,0,s2-1);
			y++;
		}
	}
	cout << ans << "\n";
	return 0;
}
