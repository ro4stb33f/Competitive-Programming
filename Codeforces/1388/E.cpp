#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ld pi = 4*atan(1);
const ld eps = 1e-9;
const ld pinf = 1e9;

struct Line {
	mutable ld k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ld inf = 1/.0;
	ld div(ld a, ld b) { // floored division
		return a / b;}
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ld k, ld m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ld query(ld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<ll,pair<ll,ll>>> segs(n);
	for (int q = 0; q < n; q++)
	{
		cin >> segs[q].second.first >> segs[q].second.second >> segs[q].first;
	}
	sort(segs.begin(), segs.end());
	bool samey = true;
	ll minx = segs[0].second.first, maxx = segs[0].second.second;
	for (int q = 1; q < n; q++)
	{
		if (segs[q].first != segs[q-1].first)
			samey = false;
		minx = min(minx, segs[q].second.first);
		maxx = max(maxx, segs[q].second.second);
	}
	if (samey)
	{
		cout << maxx - minx << "\n";
		return 0;
	}
	vector<pair<ld,int>> slopepos;
	vector<pair<ld, int>> slopeneg;
	int cur = 0;
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < q && segs[w].first < segs[q].first; w++)
		{
			ld a1,a2;
			if (segs[q].second.first - segs[w].second.second != 0)
			{
				a1 = (ld)(segs[q].first - segs[w].first)/(segs[q].second.first - segs[w].second.second);
			}
			else
				a1 = pinf;
			if (segs[q].second.second - segs[w].second.first != 0)
			{
				a2 = (ld)(segs[q].first - segs[w].first)/(segs[q].second.second - segs[w].second.first);
			}
			else
				a2 = pinf;
			if (a1 < 0) slopeneg.emplace_back(a1,cur);
			else slopepos.emplace_back(a1,cur);
			if (a2 < 0) slopeneg.emplace_back(a2,cur);
			else slopepos.emplace_back(a2,cur);
			cur++;
		}
	}
	sort(slopepos.begin(), slopepos.end());
	sort(slopeneg.begin(), slopeneg.end());
	for (auto e : slopeneg) slopepos.push_back(e);
	vector<bool> seen(2e6+1);
	vector<bool> isin(2e6+1);
	int curin = 0;
	vector<ld> goodangles;
	int l = 0, r = 0, sz = slopepos.size();
	while (l < sz)
	{
		while (r+1 < sz && abs(slopepos[r+1].first - slopepos[l].first) <= eps) r++;
		int ctin = 0;
		for (int q = l; q <= r; q++)
			if (isin[slopepos[q].second]) ctin++;
		if (ctin == curin || curin == 0)
		{
			goodangles.push_back(slopepos[l].first);
		}
		for (int q = l; q <= r; q++)
		{
			if (curin == 0)
			{
				if (!seen[slopepos[q].second])
				{
					isin[slopepos[q].second] = true;
					curin++;
				}
			}
			else
			{
				if (isin[slopepos[q].second])
				{
					isin[slopepos[q].second] = false;
					curin--;
				}
				else
				{
					isin[slopepos[q].second] = true;
					curin++;
				}
			}
			seen[slopepos[q].second] = true;
		}
		l = r+1, r = l;
	}
	LineContainer mi;
	LineContainer ma;
	for (int q = 0; q < n; q++)
	{
		ma.add(-segs[q].first, segs[q].second.second);
		mi.add(segs[q].first, -segs[q].second.first);
	}
	ld ans = 1e18;
	for (ld a : goodangles)
	{
		ld mii = -mi.query(1.0/a);
		ld maa = ma.query(1.0/a);
		ans = min(ans, maa - mii);
	}
	cout << fixed << setprecision(11) << ans << "\n";
	return 0;
}
	
