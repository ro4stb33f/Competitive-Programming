#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> dx = {1,1};
vector<int> dy = {0,1};

void solve()
{
	int n,k,l;
	cin >> n >> k >> l;
	vector<vector<int>> depth(2*k, vector<int>(n));
	vector<vector<bool>> visited(2*k, vector<bool>(n));
	for (int q = 0; q < n; q++)
	{
		cin >> depth[0][q];
	}
	for (int q = 1; q < k+1; q++)
	{
		for (int w = 0; w < n; w++)
		{
			depth[q][w] = depth[q-1][w]+1;
		}
	}
	for (int q = k+1; q < 2*k; q++)
	{
		for (int w = 0; w < n; w++)
		{
			depth[q][w] = depth[q-1][w]-1;
		}
	}
	queue<pair<int,int>> bfs;
	for (int q = 0; q < 2*k; q++)
	{
		if (depth[q][0] <= l)
		{
			visited[q][0] = true;
			bfs.push({q,0});
		}
	}
	if(bfs.empty())
	{
		cout << "No\n";
		return;
	}
	while (!bfs.empty())
	{
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();
		for (int q = 0; q < 2; q++)
		{
			int nx = (x+dx[q]) % (2*k);
			int ny = y+dy[q];
			if (ny == n)
			{
				cout << "Yes\n";
				return;
			}
			if (!visited[nx][ny] && depth[nx][ny] <= l)
			{
				visited[nx][ny] = true;
				bfs.push({nx,ny});
			}
		}
	}
	cout << "No\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

