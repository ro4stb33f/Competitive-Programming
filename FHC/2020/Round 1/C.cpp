#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e6;
vector<int> adj[mx+1];
vector<int> adj1[mx+1];
int n;
string s;
vector<bool> visited(mx+1);
vector<int> groupsz(mx+1);
vector<int> belong(mx+1);
vector<int> subtreesz(mx+1);
vector<pair<int,int>> edges;
vector<pair<int,int>> edges1;
int cur = 0;
ll ans = 0;
ll numbergood = 0;
ll largest = 0;
ll secondlargest = 0;
ll numberlargest = 0;
void dfs(int v, int p)
{
	groupsz[cur]++;
	visited[v] = true;
	belong[v] = cur;
	for (int a : adj[v])
	{
		if (!visited[a] && s[a-1]=='*')
		{
			dfs(a,v);
		}
	}
}

void dfs2(int v, int p)
{
	subtreesz[v] = 1;
	for (int a : adj[v])
	{
		if (a != p)
		{
			dfs2(a,v);
			subtreesz[v] += subtreesz[a];
		}
	}
}
void dfs3(int v, int p)
{
	subtreesz[v] = 1;
	for (int a : adj[v])
	{
		if (a != p && s[a-1] == '*')
		{
			dfs3(a,v);
			subtreesz[v] += subtreesz[a];
		}
	}
}

void dfs4(int v, int p)
{
	subtreesz[v] = 1;
	for (int a : adj1[v])
	{
		if (a != p)
		{
			dfs4(a,v);
			subtreesz[v] += subtreesz[a];
		}
	}
}

void dfs5(int v, int p)
{
	subtreesz[v] = (groupsz[v] == largest ? 1 : 0);
	for (int a : adj1[v])
	{
		if (a != p)
		{
			dfs5(a,v);
			subtreesz[v] += subtreesz[a];
		}
	}
}

void solve1()
{
	dfs2(1,0);
	for (auto e : edges)
	{
		int x = e.first;
		int y = e.second;
		ll a = min(subtreesz[x], subtreesz[y]);
		ans += a * (n - a);
	}
}

void solve2()
{
	int root = -1;
	for (int q = 0; q < n; q++)
	{
		if (s[q] == '*')
		{
			root = q+1;
			break;
		}
	}
	dfs3(root, 0);
	for (auto e : edges)
	{
		int x,y;
		tie(x,y) = e;
		if (s[x-1] != '*' || s[y-1] != '*')
		{
			continue;
		}
		ll a = min(subtreesz[x], subtreesz[y]);
		ans += a * (numbergood - a);
	}
	root = belong[root];
	dfs4(root, 0);
	for (auto e : edges1)
	{
		int x,y;
		tie(x,y) = e;
		ll a = min(subtreesz[x], subtreesz[y]);
		ans += a * (n-a);
	}
}

void solve3()
{
	dfs5(1,0);
	for (auto e : edges1)
	{
		int x,y;
		tie(x,y) = e;
		ll a = min(subtreesz[x], subtreesz[y]);
		ans += a * largest * (numberlargest - a) * largest;
	}
}

void solve4()
{
	int root = -1;
	for (int q = 1; q <= cur; q++)
	{
		if (groupsz[q] == largest)
		{
			root = q;
			break;
		}
	}
	vector<int> dist(cur+1,-2);
	dist[root] = 0;
	queue<int> bfs;
	bfs.push(root);
	while (!bfs.empty())
	{
		int f = bfs.front();
		bfs.pop();
		for (int a : adj1[f])
		{
			if (dist[a] == -2)
			{
				dist[a] = dist[f]+1;
				if (groupsz[a] == secondlargest)
				{
					ans += (ll)largest * secondlargest * dist[a];
				}
				bfs.push(a);
			}
		}
	}
}

void solve()
{
	numbergood = 0;
	ans = 0;
	numberlargest = 0;
	cur = 0;
	int k;
	cin >> n >> k >> s;
	for (int q = 0; q < n; q++)
	{
		if (s[q] == '*')
		{
			numbergood++;
		}
	}
	for (int q = 1; q <= n; q++)
	{
		adj[q].clear();
		belong[q] = -1;
		groupsz[q] = 0;
	}
	edges.clear();
	fill(visited.begin(), visited.begin()+(n+1), false);
	visited[0] = true;
	ll es[2];
	for (int q = 2; q <= k+1; q++)
	{
		cin >> es[q%2];
		adj[es[q%2]].push_back(q);
		adj[q].push_back(es[q%2]);
		edges.emplace_back(q, es[q%2]);
	}
	ll a,b,c;
	cin >> a >> b >> c;
	for (ll q = k+2; q <= n; q++)
	{
		ll x = (a*es[q%2]+b*es[1-(q%2)]+c)%(q-1) + 1;
		es[q%2] = x;
		adj[q].push_back(x);
		adj[x].push_back(q);
		edges.emplace_back(q,x);
	}
	vector<int> goodgroupsz;
	for (int q = 1; q <= n; q++)
	{
		if (!visited[q])
		{
			cur++;
			if (s[q-1]=='#')
			{
				belong[q] = cur;
				visited[q] = true;
			}
			else
			{
				dfs(q,0);
			}
			goodgroupsz.push_back(groupsz[cur]);
		}
	}
	sort(goodgroupsz.rbegin(), goodgroupsz.rend());
	ans = 0;
	if (goodgroupsz.size() == 1 || goodgroupsz[0] == 0)
	{
		//check ways to remove edge and reconnect, they all work
		solve1();
		if (goodgroupsz[0] == 0)
		{
			cout << "0 " << ans << "\n";
			return;
		}
		else
		{
			ll nn = n;
			cout << nn * (nn-1) / 2 << " " << ans << "\n";
			return;
		}
	}
	for (int q = 1; q <= cur; q++)
	{
		adj1[q].clear();
	}
	edges1.clear();
	for (auto e : edges)
	{
		int x,y;
		tie(x,y) = e;
		if (belong[x] != belong[y])
		{
			adj1[belong[x]].push_back(belong[y]);
			adj1[belong[y]].push_back(belong[x]);
			edges1.emplace_back(belong[x], belong[y]);
		}
	}
	if (goodgroupsz[1] == 0)
	{
		//one good blob, rest are bad
		solve2();
		ll nn = numbergood;
		cout << nn * (nn-1) /2 << " " << ans << "\n";
		return;
	}
	ll totalgood = 0;
	for (int q = 0; q < cur; q++)
	{
		if (goodgroupsz[0] == goodgroupsz[q])
		{
			numberlargest++;
		}
		ll x = goodgroupsz[q];
		totalgood += x * (x-1)/2;
	}
	largest = goodgroupsz[0];
	secondlargest = goodgroupsz[1];
	if (largest == secondlargest)
	{
		//take blobs that are all max size
		solve3();
		cout << totalgood + largest*largest << " " << ans << "\n";
		return;
	}
	//one blob is maximal, so bfs from it to the second maximal value
	solve4();
	cout << totalgood + largest * secondlargest << " " << ans << "\n";
}

int main()
{
	freopen("quarantine_validation_input.txt", "r", stdin);
	freopen("test.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cout << "Case #" << q << ": ";
		solve();
	}
	return 0;
}
