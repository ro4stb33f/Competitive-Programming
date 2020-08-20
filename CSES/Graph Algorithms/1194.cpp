#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	string grid[n];
	for (int q = 0; q < n; q++)
	{
		cin >> grid[q];
	}
	
	vector<vector<pair<int, int>>> visited(n, vector<pair<int, int>>(m));
	queue<tuple<int, int, int>> bfs;
	pair<int, int> person;
	for (int q = 0; q < n; q++)
	{
		for (int w = 0; w < m; w++)
		{
			if (grid[q][w] == 'M')
			{
				visited[q][w] = {1, 0};
				bfs.push(make_tuple(q,w,1));
			}
			if (grid[q][w] == 'A')
			{
				visited[q][w] = {2,0};
				person.first = q;
				person.second = w;
			}
		}
	}
	bfs.push(make_tuple(person.first, person.second, 2));
	while (!bfs.empty())
	{
		int sz = bfs.size();
		for (int q = 0; q < sz; q++)
		{
			tuple<int,int,int> t = bfs.front();
			bfs.pop();
			int x = get<0>(t);
			int y = get<1>(t);
			int type = get<2>(t);
			if (x > 0 && visited[x-1][y].first == 0 && grid[x-1][y] == '.')
			{
				visited[x-1][y] = {type, 1};
				bfs.push(make_tuple(x-1, y, type));
			}
			if (x < n-1 && visited[x+1][y].first == 0 && grid[x+1][y] == '.')
			{
				visited[x+1][y] = {type, 3};
				bfs.push(make_tuple(x+1, y, type));
			}
			if (y > 0 && visited[x][y-1].first == 0 && grid[x][y-1] == '.')
			{
				visited[x][y-1] = {type, 4};
				bfs.push(make_tuple(x, y-1, type));
			}
			if (y < m-1 && visited[x][y+1].first == 0 && grid[x][y+1] == '.')
			{
				visited[x][y+1] = {type, 2};
				bfs.push(make_tuple(x, y+1, type));
			}
			
		}
	}
	pair<int,int> valid;
	valid.first = -1;
	valid.second = -1;
	for (int q = 0; q < m; q++)
	{
		if (grid[0][q] != '#' && visited[0][q].first == 2)
		{
			valid.first = 0;
			valid.second = q;
			break;
		}
		if (grid[n-1][q] != '#' && visited[n-1][q].first == 2)
		{
			valid.first = n-1;
			valid.second = q;
			break;
		}
	}
	if (valid.first == -1)
	{
		for (int q = 0; q < n; q++)
		{
			if (grid[q][0] != '#' && visited[q][0].first == 2)
			{
				valid.first = q;
				valid.second = 0;
				break;
			}
			if (grid[q][m-1] != '#' && visited[q][m-1].first == 2)
			{
				valid.first = q;
				valid.second = m-1;
				break;
			}
		}
	}
	if (valid.first == -1)
	{
		cout << "NO\n";
		return 0;
	}
	int x = valid.first, y= valid.second;
	vector<int> moves;
	while (visited[x][y].second != 0)
	{
		int z = visited[x][y].second;
		moves.push_back(z);
		if (z == 1)
		{
			x++;
		}
		else if (z == 2)
		{
			y--;
		}
		else if (z == 3)
		{
			x--;
		}
		else
		{
			y++;
		}
	}
	int sz = moves.size();
	cout << "YES\n" << sz << "\n";
	for (int q = sz-1; q >= 0; q--)
	{
		if (moves[q] == 1)
		{
			cout << "U";
		}
		else if (moves[q] == 2)
		{
			cout << "R";
		}
		else if (moves[q] == 3)
		{
			cout << "D";
		}
		else
		{
			cout << "L";
		}
	}
	return 0;
}
