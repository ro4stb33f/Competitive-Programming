#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
	//srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int q = 0; q < n; q++)
	{
		cin >> a[q];
		//a[q] = (rand() % 15) + 1;
	}
	/*for (int q = 0; q < n; q++)
	{
		cout << a[q] << " ";
	}
	cout << "aa\n";*/
	// check first, second, third
	if (n == 1)
	{
		cout << a[0] << "\n";
		return 0;
	}
	if (n == 3)
	{
		cout << max(a[0]+a[1], max(a[0]+a[2], a[1]+a[2])) << "\n";
		return 0;
	}
	ll ans = LLONG_MIN;
	for (int q = 0; q < 3; q++)
	{
		vector<ll> b;
		for (int w = 0; w < n; w++)
		{
			b.push_back(a[(q+w) % n]);
		}
		vector<ll> sumevens(n);
		sumevens[0] = b[0];
		for (int w = 2; w < n; w+=2)
		{
			sumevens[w] = sumevens[w-2] + b[w]; 
		}
		vector<ll> sumodds(n);
		sumodds[n-2] = b[n-2];
		for (int w = n-4; w >= 1; w-=2)
		{
			sumodds[w] = sumodds[w+2] + b[w];
		}
		ll best = max(sumevens[0] + sumodds[1], sumevens[n-1]);
		for (int w = 2; w < n-1; w+=2)
		{
			best = max(best, sumevens[w] + sumodds[w+1]);
		}
		//cout << q << " " << best << " cc\n";
		ans = max(ans, best);
	}
	cout << ans << "\n"; 
	return 0;
}

