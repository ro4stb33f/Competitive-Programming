#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
void mult(ll a[2][2], ll b[2][2])
{
	ll temp[2][2];
	for (int q = 0; q < 2; q++)
	{
		for (int w = 0; w < 2; w++)
		{
			temp[q][w] = 0;
			for (int e = 0; e < 2; e++)
			{
				temp[q][w] = (temp[q][w] + (a[q][e] * b[e][w]) % md) % md;
			}
		}
	}
	for (int q = 0; q < 2; q++)
	{
		for (int w=  0; w < 2; w++)
		{
			a[q][w] = temp[q][w];
		}
	}
}

void pow(ll a[2][2], ll b)
{
	if (b <= 1)
	{
		return;
	}
	ll temp[2][2];
	for (int q = 0; q < 2; q++)
	{
		for (int w = 0; w < 2; w++)
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
	ll x[2][2];
	for (int q = 0; q < 2; q++)
	{
		for (int w = 0; w < 2; w++)
		{
			x[q][w] = q|w;
		}
	}
	pow(x,n-1);
	cout << x[1][1] << "\n";
	return 0;
}
