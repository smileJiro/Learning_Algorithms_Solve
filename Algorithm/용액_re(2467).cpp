#include <bits/stdc++.h>
using namespace std;

// binary search
using ll = long long;
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<ll> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	int l{ 0 }, r{N - 1};


	ll minSum{ LLONG_MAX };
	int aL, aR;
	while (l < r)
	{
		ll sum = arr[l] + arr[r];
		if (minSum > abs(arr[l] + arr[r]))
		{
			aL = l; aR = r;
			minSum = abs(arr[l] + arr[r]);

			if (0 == sum)
				break;
		}
		
		if (sum < 0)
			++l;
		else
			--r;


	}
	cout << arr[aL]<< ' ' << arr[aR];
	return 0;
}