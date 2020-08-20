#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int l, int r)
{
	return uniform_int_distribution<int>(l,r)(rng);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	//n = 10;
	cin >> n;
	vector<vector<int>> mod(n);
	for (int q = 0; q < n; q++)
	{
		int a;
		//a = getrand(1,19);
		cin >> a;
		mod[a%n].push_back(a);
		//cout << a << " ";
	}
	//cout << "\n";
	if (mod[0].size() > 0)
	{
		cout << "1\n";
		cout << mod[0][0] << "\n";
		return 0;
	}
	vector<int> achievable(n, -1);
	for (int q = 1; q < n; q++)
	{
		int cur = 0;
		for (int w : mod[q])
		{
			cur += q;
			cur %= n;
			if (cur == 0)
			{
				int cur1 = 0;
				vector<int> ans;
				for (int e : mod[q])
				{
					cur1 += q;
					cur1 %= n;
					ans.push_back(e);
					if (cur1 == 0)
					{
						break;
					}
				}
				cout << ans.size() << "\n";
				for (int e : ans)
				{
					cout << e << "\n";
				}
				return 0;
			}
			if (achievable[n-cur] != -1 && achievable[n-cur] != q)
			{
				int x = achievable[n-cur];
				vector<int> ans;
				int cur1 = 0;
				for (int e : mod[x])
				{
					cur1 += e;
					cur1 %= n;
					ans.push_back(e);
					if (cur1 == n-cur)
					{
						break;
					}
				}
				int cur2 = 0;
				for (int e : mod[q])
				{
					cur2 += e;
					cur2 %= n;
					ans.push_back(e);
					if (cur2 == cur)
					{
						break;
					}
				}
				cout << ans.size() << "\n";
				for (int e : ans)
				{
					cout << e << "\n";
				}
				return 0;
			}
			if (achievable[cur] == -1)
			{
				achievable[cur] = q;
			}
		}
	}
	if (achievable[0] != -1)
	{
		vector<int> ans;
		int x = achievable[0];
		int cur = 0;
		for (int q : mod[x])
		{
			cur += x;
			cur %= n;
			ans.push_back(q);
			if (cur == 0)
			{
				break;
			}
		}
		cout << ans.size() << "\n";
		for (int q : ans)
		{
			cout << q << "\n";
		}
		return 0;
	}
	cout << "0\n";
	return 0;
}
