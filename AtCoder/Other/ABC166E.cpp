#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    cin >> n;
    map<int, ll> f1;
    map<int, ll> f2;
    for (int q = 1; q <= n; q++)
    {
        int a;
        cin >> a;
        int val1 = a - q;
        int val2 = a + q;
        if (f1.find(val1) == f1.end())
        {
            f1[val1] = 1;
        }
        else
        {
            f1[val1]++;
        }
        if (f2.find(val2) == f2.end())
        {
            f2[val2] = 1;
        }
        else
        {
            f2[val2]++;
        }
    }
    auto it = f1.begin();
    ll tot = 0;
    while (it != f1.end())
    {
        int val = it->first;
        auto it2 = f2.find(-1 * val);
        if (it2 != f2.end())
        {
            tot += it->second * it2->second;
        }
        it++;
    }
    cout << tot;
}
