#include <bits/stdc++.h>
using namespace std;


// 보이는 면 개수: 1개 ~ 5개
// n == 1 이면 5개, 이외에는 3,2,1의 조합 
// 보이는 면 개수별 최소값을 구한다. 


enum Dir { R, D, L, U };
int dice[6];
int sorted[6];
constexpr int neighborIndex[6][4] =  // 각 숫자별 이웃 인덱스
{
	{ 1, 2, 4, 3 },
	{ 5, 2, 0, 3 },
	{ 1, 5, 4, 0 },
	{ 1, 0, 4, 5 },
	{ 0, 2, 5, 3 },
	{ 4, 2, 1, 3 }
};
long long minVisibleSide[3] = { LLONG_MAX, LLONG_MAX, LLONG_MAX };
long long N;
void ComputeSum_VisibleSide()
{
	for (int i = 0; i < 6; ++i)
		sorted[i] = dice[i];
	sort(sorted, sorted + 6);

	// 1면
	minVisibleSide[0] = sorted[0];

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			long long twoSum = dice[i] + dice[neighborIndex[i][j]];
			minVisibleSide[1] = min(minVisibleSide[1], twoSum);

			long long threeSum =
				dice[i]
				+ dice[neighborIndex[i][j]]
				+ dice[neighborIndex[i][(j + 1) % 4]];

			minVisibleSide[2] = min(minVisibleSide[2], threeSum);
		}
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 6; ++i)
	{
		cin >> dice[i];
	}

	ComputeSum_VisibleSide();

	long long answer = 0;
	if (N == 1)
	{
		for (int i = 0; i < 5; ++i)
			answer += sorted[i];
	}
	else
	{
		long long ThreeCount = 4;
		long long TwoCount = (N - 2) * 8 + 4;
		long long OneCount = ((N - 2) * (N - 2) * 5) + ((N - 2) * 4);

		answer += ThreeCount * minVisibleSide[2];
		answer += TwoCount * minVisibleSide[1];
		answer += OneCount * minVisibleSide[0];
	}
	cout << answer << '\n';
	return 0;
}