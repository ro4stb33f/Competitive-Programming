#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll pow(ll a, ll b)
{
	if (b == 0)
	{
		return 1LL;
	}
	ll ans = pow(a,b/2);
	ans = ans * ans;
	if (b % 2 == 1)
	{
		ans = ans * a;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll k;
	cin >> k;
	ll cur = 1;
	string s = "codeforces";
	while (pow(cur,10) < k)
	{
		cur++;
	}
	ll amt[10];
	for (ll q = 10; q >= 0; q--)
	{
		if (pow(cur-1,q) * pow(cur, 10-q) >= k)
		{
			for (int w = 0; w < q; w++)
			{
				amt[w] = cur-1;
			}
			for (int w = q; w < 10; w++)
			{
				amt[w] = cur;
			}				
			break;		
		}
	}
	for (int q = 0; q < 10; q++)
	{
		for (int w = 1; w <= amt[q]; w++)
		{
			cout << s[q];
		}
	}
	cout << "\n";
	return 0;
}

