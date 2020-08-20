#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> comp;
vector<int> sz;
int numcomps;

int root(int a)
{
	int acpy = a;
	while (a != comp[a])
	{
		a = comp[a];
	}
	comp[acpy] = a;
	return a;
}

bool unite(int a, int b)
{
	int x = root(a), y = root(b);
	if (x==y)
	{
		return false;
	}
	if (sz[x] > y)
	{
		swap(x,y);
	}
	comp[x] = y;
	sz[y] += sz[x];
	numcomps--;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	numcomps = n;
	comp.push_back(0);
	sz.push_back(0);
	vector<pair<int,int>> order;
	for (int q = 1; q <= n; q++)
	{
		int a,b;
		cin >> a >> b;
		order.emplace_back(a,q);
		order.emplace_back(b,q);
		comp.push_back(q);
		sz.push_back(1);
	}
	sort(order.begin(), order.end());
	int numedges = 0;
	vector<bool> onstack(n+1);
	stack<int> cur;
	stack<int> rstack;
	for (int q = 0; q < 2*n; q++)
	{
		int a = order[q].second;
		if (!onstack[a])
		{
			cur.push(a);
			onstack[a] = true;
		}
		else
		{
			while (cur.top() != a)
			{
				numedges++;
				if (numedges >= n)
				{
					cout << "NO\n";
					return 0;
				}
				int b = cur.top();
				cur.pop();
				rstack.push(b);
				unite(a,b);
			}
			cur.pop();
			while (!rstack.empty())
			{
				int b = rstack.top();
				rstack.pop();
				cur.push(b);
			}
		}
	}
	if (numcomps == 1)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}

