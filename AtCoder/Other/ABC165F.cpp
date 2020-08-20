#include <bits/stdc++.h>
using namespace std;
#define mx  200005
vector<int> adj[mx];
vector<int> val(mx);
vector<int> lis(mx, -1);
vector<int> currseq;
void dfs(int a)
{
    auto it = lower_bound(currseq.begin(), currseq.end(), val[a]);
    int prevval = -1;
    int index = -1;
    if (it == currseq.end())
    {
        currseq.push_back(val[a]);
    }
    else
    {
        index = it - currseq.begin();
        prevval = currseq[index];
        currseq[index] = val[a];
    }
    lis[a] = currseq.size();
    for (int s : adj[a])
    {
        if (lis[s] == -1)
        {
            dfs(s);
        }
    }
    if (prevval == -1)
    {
        currseq.pop_back();
    }
    else
    {
        currseq[index] = prevval;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int q = 1; q <= n; q++)
    {
        cin >> val[q];
    }
    for (int q = 0; q < n-1; q++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for (int q = 1; q <= n; q++)
    {
        cout << lis[q] << endl;
    }
    return 0;
}
