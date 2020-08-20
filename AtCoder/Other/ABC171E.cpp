#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> cat(n);
	int res = 0;
	for (int q = 0; q < n; q++)
	{
		cin >> cat[q];
		res ^=cat[q];
	}
	for (int q = 0; q < n; q++)
	{
		cout << (cat[q] ^ res) << " ";
	}
	cout << "\n";
	return 0;
}
