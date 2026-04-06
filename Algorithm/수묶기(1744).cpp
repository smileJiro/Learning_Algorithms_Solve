#include <bits/stdc++.h>

using namespace std;



int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	// 음수 내림차순, 양수 내림차순 정렬한다.

	vector<int> negative;
	vector<int> positive;
	long long sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		if (num <= 0)
		{
			negative.push_back(num);
		}
		else if (num == 1)
		{
			sum += 1;
		}
		else
		{
			positive.push_back(num);
		}
	}

	sort(negative.begin(), negative.end(), less<int>());
	sort(positive.begin(), positive.end(), greater<int>());

	{
		if (negative.size() % 2)
		{
			sum += negative.back();
			negative.pop_back();
		}

		if (!negative.empty())
		{
			int size = negative.size();
			for (int i = 0; i < size - 1; i += 2)
			{
				sum += negative[i] * negative[i + 1];
			}
		}

	}

	{
		if (positive.size() % 2)
		{
			sum += positive.back();
			positive.pop_back();
		}

		if (!positive.empty())
		{
			int size = positive.size();
			for (int i = 0; i < size - 1; i += 2)
			{
				sum += positive[i] * positive[i + 1];
			}
		}

	}

	cout << sum << '\n';
	return 0;
}