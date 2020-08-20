#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
void solve()
{
	ll n,k;
	cin >> n >> k;
	ll left[n];
	for (int q = 0; q < k; q++)
	{
		cin >> left[q];
	}
	ll al,bl,cl,dl;
	cin >> al >> bl >> cl >> dl;
	for (int q = k; q < n; q++)
	{
		left[q] = ((al * left[q-2] + bl * left[q-1])%dl	+ cl)%dl + 1;
	}
	ll width[n];
	for (int q = 0; q < k; q++)
	{
		cin >> width[q];
	}
	ll aw,bw,cw,dw;
	cin >> aw >> bw >> cw >> dw;
	for (int q = k; q < n; q++)
	{
		width[q] = ((aw * width[q-2] + bw * width[q-1])%dw + cw)%dw + 1;
	}
	ll height[n];
	for (int q = 0; q < k; q++)
	{
		cin >> height[q];
	}
	ll ah,bh,ch,dh;
	cin >> ah >> bh >> ch >> dh;
	for (int q = k; q < n; q++)
	{
		height[q] = ((ah * height[q-2] + bh * height[q-1])%dh + ch)%dh + 1;
	}
	set<pair<ll,ll>> intervals;
	ll ans = 1LL;
	ll cur = 0;
	for (int q = 0; q < n; q++)
	{
		if (intervals.size() == 0)
		{
			cur += 2 * (width[q] + height[q]);
			cur %= md;
			intervals.insert({left[q], left[q]+width[q]});
		}
		else
		{
			ll intersect = 0;
			ll horizontaladd = width[q];
			ll newleft = left[q];
			ll newright = left[q]+width[q];
			auto it1 = intervals.lower_bound({left[q], 0});
			if (it1 != intervals.begin())
			{
				auto it2 = it1;
				it2--;
				if (it2->second >= left[q])
				{
					newleft = it2->first;
					intersect++;
					horizontaladd -= (min(it2->second, left[q]+width[q]) - left[q]);
					newright = max(newright, it2->second);
					intervals.erase(it2);
				}
			}
			while (it1 != intervals.end() && it1->first <= left[q]+width[q])
			{
				intersect++;
				if (it1->second >= left[q]+width[q])
				{
					newright = max(newright, it1->second);
					//cout << left[q] + width[q] << " " << it1->first << " CC\n";
					horizontaladd -= (left[q]+width[q] - it1->first);
					auto it2 = it1;
					it1++;
					intervals.erase(it2);
				}
				else
				{
					horizontaladd -= (it1->second - it1->first);
					auto it2 = it1;
					it1++;
					intervals.erase(it2);
				}
			}
			//cout << horizontaladd << " BB\n";
			cur += (2LL * horizontaladd);
			cur %= md;
			cur = cur - (2LL * intersect - 2LL) * height[q];
			cur = ((cur % md) + md) % md;
			intervals.insert({newleft, newright});
		}
		//cout << cur << " AA\n";
		ans *= cur;
		ans %= md;
	}
	cout << ans << "\n";
}

int main()
{
	freopen("perimetric_chapter_2_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ": ";
		solve();
	}
	return 0;
}
