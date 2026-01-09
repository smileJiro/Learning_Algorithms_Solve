#include <bits/stdc++.h>
using namespace std;


int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;


	vector<int> trees(N, 0);
	int maxHeight = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> trees[i];
		maxHeight = max(maxHeight, trees[i]);
	}


	// 이진탐색 (mid == 절단기 높이)
	int s{ 0 }, e{ maxHeight }, m{};
	int answer{ 0 };
	while (s <= e)
	{
		m = (s + e) / 2;

		long long sum = 0;
		for (int h : trees)
		{
			sum += max(0, h - m);
		}

		if (sum >= M) // 나무가 충분한 경우 -> 절단기 높이를 더 올려본다
		{
			s = m + 1;
			answer = m;
		}
		else // 나무가 부족한 경우 -> 절단기 높이를 낮춘다.
		{
			e = m - 1;
		}
	}


	cout << answer << '\n';

	return 0;
}