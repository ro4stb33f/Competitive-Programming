#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll k;
	cin >> k;
	ll ans[50];
	for (ll q = 0; q < 50; q++)
	{
		ans[q] = q + k/50;
	}
	ll extra = k%50;
	for (ll q = 0; q < extra; q++)
	{
		int idx = 0;
		for (int w = 0; w < 50; w++)
		{
			if (ans[w] < ans[idx])
			{
				idx = w;
			}
		}
		for (int w = 0; w < 50; w++)
		{
			ans[w]--;
		}
		ans[idx]+=51;
	}
	cout << "50\n";
	for (int q = 0; q < 50; q++)
	{
		cout << ans[q] << " ";
	}
	cout << "\n";
	return 0;
}
