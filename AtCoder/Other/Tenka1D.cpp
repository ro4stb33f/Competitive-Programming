#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> triangle(449);
	triangle[1] = 1;
	for (int q = 2; q <= 448; q++)
	{
		triangle[q] = triangle[q-1]+q;
	}
	int n;
	cin >> n;
	int num = -1;
	for (int q = 1; q <= 448; q++)
	{
		if (n == triangle[q])
		{
			num = q;
			break;
		}
	}
	if (num == -1)
	{
		cout << "No\n";
		return 0;
	}
	vector<vector<int>> ans(num+1, vector<int>(num));
	int cur = 0;
	int used = 0;
	while (cur < num)
	{
		for (int q = cur; q < num; q++)
		{
			ans[cur][q] = used+(q-cur+1);
		}
		for (int q = cur+1; q < num+1; q++)
		{
			ans[q][cur] = used + q- cur;
		}
		used += num-cur;
		cur++;
	}
	cout << "Yes\n";
	cout << (num+1) << "\n";
	for (int q = 0; q < num+1; q++)
	{
		cout << num << " ";
		for (int w = 0; w < num; w++)
		{
			cout << ans[q][w] << " ";
		}
		cout << "\n";
	}
	return 0;
}
