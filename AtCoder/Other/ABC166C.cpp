#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int height[n+1];
    for (int q = 1; q <= n; q++)
    {
        cin >> height[q];
    }
    vector<bool> good(n+1, true);
    for (int q = 0; q < m; q++)
    {
        int a,b;
        cin >> a >> b;
        if (height[a] == height[b])
        {
            good[a] = false;
            good[b] = false;
            continue;
        }
        if (height[a] < height[b])
        {
            good[a] = false;
        }
        else
        {
            good[b] = false;
        }
    }
    int tot = 0;
    for (int q = 1; q <= n; q++)
    {
        if (good[q])
        {
            tot++;
        }
    }
    cout << tot;
}
