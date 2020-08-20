#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll n, x;
	cin >> n >> x;
	vector<ll> monthsizes(n);
	vector<ll> monthsum(n);
	vector<ll> prefixmonthsizes(n);
	vector<ll> prefixmonthsums(n);
	vector<ll> suffixmonthsizes(n);
	vector<ll> suffixmonthsums(n);
	ll yeardays = 0;
	ll yearhugs = 0;
	for (int q = 0; q < n; q++)
	{
		cin >> monthsizes[q];
		monthsum[q] = monthsizes[q] * (monthsizes[q]+1) / 2;
		yearhugs += monthsum[q];
		prefixmonthsums[q] = yearhugs;
		yeardays += monthsizes[q];
		prefixmonthsizes[q] = yeardays;
	}
	suffixmonthsizes[n-1] = - 1 * monthsizes[n-1];
	suffixmonthsums[n-1] = monthsum[n-1];
	for (int q = n-2; q >= 0; q--)
	{
		suffixmonthsizes[q] = -1 * monthsizes[q] + suffixmonthsizes[q+1];
		suffixmonthsums[q] = monthsum[q] + suffixmonthsums[q+1];
	}
	ll adjusted = x % yeardays;
	if (adjusted == 0)
	{
		cout << x/yeardays * yearhugs << "\n";
		return 0;
	}
	ll mxhugs = 0;
	//check start on first day of month
	for (int q = 0; q < n; q++)
	{
		ll prevdays = 0;
		ll prevhugs = 0;
		ll tothugs = 0;
		if (q > 0)
		{
			prevdays = prefixmonthsizes[q-1];
			prevhugs = prefixmonthsums[q-1];
		}
		if (yeardays - prevdays < adjusted)
		{
			tothugs += (yearhugs - prevhugs);
			ll remaining = adjusted - (yeardays - prevdays);
			//wrap around
			auto it = lower_bound(prefixmonthsizes.begin(), prefixmonthsizes.end(), remaining);
			ll extrahugdays = remaining;
			if (it != prefixmonthsizes.begin())
			{
				it--;
				int index = it - prefixmonthsizes.begin();
				tothugs += prefixmonthsums[index];
				extrahugdays = remaining - *it;
			}
			tothugs += (extrahugdays * (extrahugdays + 1)/2);
		}
		else
		{
			auto it = lower_bound(prefixmonthsizes.begin(), prefixmonthsizes.end(), prevdays + adjusted);
			ll extrahugdays = adjusted;
			if (it != prefixmonthsizes.begin())
			{
				it--;
				int index = it - prefixmonthsizes.begin();
				tothugs += (prefixmonthsums[index] - prevhugs);
				extrahugdays = adjusted + prevdays - *it;
			}
			tothugs += (extrahugdays * (extrahugdays+1)/2);
		}
		mxhugs = max(mxhugs, tothugs);
	}
	//check end of month T_T
	for (int q = 0; q < n; q++)
	{
		ll tothugs = 0;
		ll endmonth = q;
		ll remaining = adjusted;
		if (prefixmonthsizes[q] < adjusted)
		{
			//wrap around
			tothugs += prefixmonthsums[q];
			remaining = adjusted - prefixmonthsizes[q];
			endmonth = n-1;
			//rip small brain beginning of month
		}
		ll prevdays = 0;
		if (endmonth < n-1)
		{
			prevdays += (-1 * suffixmonthsizes[endmonth+1]);
		}
		ll extrahugs = remaining;
		auto it = upper_bound(suffixmonthsizes.begin(), suffixmonthsizes.end(), -1 * (prevdays + remaining));
		if (it != suffixmonthsizes.end())
		{
			int index = it - suffixmonthsizes.begin();
			tothugs += (suffixmonthsums[index]);
			if (endmonth + 1 < n)
			{
				tothugs -= (suffixmonthsums[endmonth+1]);
			}
			extrahugs = remaining + prevdays + *it;
		}
		it--;
		int previndex = it - suffixmonthsizes.begin();
		ll days = monthsizes[previndex];
		tothugs += ((2 * days - extrahugs + 1) * extrahugs / 2);
		mxhugs = max(mxhugs, tothugs);
	}
	cout << mxhugs + (x/yeardays * yearhugs)<< "\n";
	return 0;
}
