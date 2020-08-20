#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll x;
    cin >> x;
    for (ll q = -200; q <= 200; q++)
    {
        for (ll w = -200; w <= 200; w++)
        {
            if (q * q * q * q * q - w * w * w * w * w ==x)
            {
                cout << q << " " << w;
                return 0;
            }
        }
    }
    return 0;
}
