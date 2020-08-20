#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
void solve()
{
	ll n,k,w;
	cin >> n >> k >> w;
	ll len[n];
	for (int q = 0; q < k; q++)
	{
		cin >> len[q];
	}
	ll al,bl,cl,dl;
	cin >> al >> bl >> cl >> dl;
	for (int q = k; q < n; q++)
	{
		len[q] = ((al * len[q-2] + bl * len[q-1])%dl + cl)%dl + 1;
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
	deque<int> dq;
	ll cur= 0;
	ll curmax = 0;
	ll ans = 1;
	for (int q = 0; q < n; q++)
	{
		//cout << len[q] << " " << height[q] << " AA\n";
		while (!dq.empty() && len[dq.front()] + w < len[q])
		{
			dq.pop_front();
		}
		if (dq.empty())
		{
			//cout << "HERE\n";
			cur += 2LL * (w + height[q]);
			cur %= md;
			curmax = height[q];
		}
		else
		{
			cur += 2LL * (len[q] - len[q-1]);
			cur %= md;
			if (height[dq.front()] < height[q])
			{
				cur += 2LL * (height[q] - height[dq.front()]);
				cur %= md;
				curmax = max(curmax, height[q]);
			}
		}
		while (!dq.empty() && height[dq.back()] <= height[q])
		{
			dq.pop_back();
		}
		dq.push_back(q);
		ans = (((ans * cur) % md) + md) % md;
	}
	cout << ans << "\n";
}

int main()
{
	freopen("perimetric_chapter_1_input.txt", "r", stdin);
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
