#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
void mult(ll a[6][6], ll b[6][6])
{
	ll temp[6][6];
	for (int q = 0; q < 6; q++)
	{
		for (int w = 0; w < 6; w++)
		{
			temp[q][w] = 0;
			for (int e = 0; e < 6; e++)
			{
				temp[q][w] = (temp[q][w] + (a[q][e] * b[e][w]) % md) % md;
			}
		}
	}
	for (int q = 0; q < 6; q++)
	{
		for (int w=  0; w < 6; w++)
		{
			a[q][w] = temp[q][w];
		}
	}
}

void pow(ll a[6][6], ll b)
{
	if (b <= 1)
	{
		return;
	}
	ll temp[6][6];
	for (int q = 0; q < 6; q++)
	{
		for (int w = 0; w < 6; w++)
		{
			temp[q][w] = a[q][w];
		}
	}
	pow(a,b/2);
	mult(a,a);
	if (b % 2 == 1)
	{
		mult(a,temp);
	}
}

int main()
{
	ll n;
	cin >> n;
	if (n <= 1)
	{
		cout << n << "\n";
		return 0;
	}
	ll x[6][6];
	for (int q = 0; q < 6; q++)
	{
		for (int w = 0; w < 6; w++)
		{
			x[q][w] = 0;
		}
	}
	for (int q = 1; q < 6; q++)
	{
		x[q-1][q] = 1;
	}
	for (int q = 0; q < 6; q++)
	{
		x[5][q] =1;
	}
	vector<ll> base = {1,1,2,4,8,16};
	if (n < 6)
	{
		cout << base[n] << "\n";
	}
	else
	{
		pow(x,n-5);
		ll ans = 0;
		for (int q = 0; q < 6; q++)
		{
			ans = (ans + (base[q] * x[5][q]) % md) % md;
		}
		cout << ans << "\n";
	}
	return 0;
}
