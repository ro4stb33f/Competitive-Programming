#include <bits/stdc++.h>
using namespace std;

struct node{
	int prev;
	int val;
};

struct trie{
	vector<node> v;
	vector<int> place;
	int num = 1;
	int curnode = 0;
	trie()
	{
		v.push_back({0,0});
		place.push_back(0);
		place.push_back(0);
	}
	void clone(int x)
	{
		num++;
		place.push_back(place[x]);
	}
	void add(int x, int val)
	{
		v.push_back({place[x], val});
		curnode++;
		place[x] = curnode;
	}
	void remove(int x)
	{
		place[x] = v[place[x]].prev;
	}
	void reset(int x)
	{
		place[x] = 0;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	trie current, relearn;
	for (int q = 0; q < n; q++)
	{
		string s;
		int c;
		cin >> s >> c;
		if (s[0] == 'l')
		{
			int p;
			cin >> p;
			relearn.reset(c);
			current.add(c,p);
			continue;
		}
		if (s[1] == 'o')
		{
			relearn.add(c, current.v[current.place[c]].val);
			current.remove(c);
		}
		if (s[1] == 'e')
		{
			current.add(c,relearn.v[relearn.place[c]].val);
			relearn.remove(c);
		}
		if (s[1] == 'l')
		{
			current.clone(c);
			relearn.clone(c);
		}
		if (s[1] == 'h')
		{
			if (current.place[c] == 0) cout << "basic\n";
			else cout << current.v[current.place[c]].val << "\n";
		}
	}
	return 0;
}
