#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct line{
	ll m, b;
	ld xinter(line l)
	{
		return (ld) (b - l.b) / (l.m - m);
	}
	bool cmpx(line l, ll x)
	{
		return (l.m - m) * x + l.b - b >= 0;
	}
	ll evalx(ll x)
	{
		return m * x + b;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,c;
	cin >> n >> c;
	ll h[n+1];
	for (int q = 1; q <= n; q++)
	{
		cin >> h[q];
	}
	ll dp[n+1];
	dp[1] = 0;
	deque<line> dq;
	dq.push_back({-2*h[1], h[1] * h[1]});
	for (int q = 2; q <= n; q++)
	{
		while (dq.size() >= 2 && !dq.back().cmpx(dq[dq.size() - 2], h[q]))
		{
			dq.pop_back();
		}
		dp[q] = c + h[q] * h[q] + dq.back().evalx(h[q]);
		line l = {-2*h[q], h[q] * h[q]+dp[q]};
		while (dq.size() >= 2 && dq.front().xinter(l) <= dq[1].xinter(dq.front()))
		{
			dq.pop_front();
		}
		dq.push_front(l);
	}
	cout << dp[n] << "\n";
	return 0;
}
