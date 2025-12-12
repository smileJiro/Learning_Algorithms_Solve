#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;
enum POS { CENTER, TOP, LEFT, DOWN, RIGHT, LAST };
int cost[LAST][LAST] = {
	{ 0, 2, 2, 2, 2 },
	{ 0, 1, 3, 4, 3 },
	{ 0, 3, 1, 3, 4 },
	{ 0, 4, 3, 1, 3 },
	{ 0, 3, 4, 3, 1 }, };
#pragma region DP 풀이
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int dp[LAST][LAST];
	fill_n(&dp[0][0], LAST * LAST, INF);
	dp[CENTER][CENTER] = 0;
	while (true)
	{
		int x;
		cin >> x;
		if (x == 0)
			break;

		int ndp[LAST][LAST];

		// ndp: ndp[]
		fill_n(&ndp[0][0], LAST * LAST, INF);
		for (int l = 0; l < LAST; ++l)
		{
			for (int r = 0; r < LAST; ++r)
			{
				if (dp[l][r] == INF)
					continue;
				// 오른발로 누르는 경우
				ndp[l][x] = min(ndp[l][x], dp[l][r] + cost[r][x]);

				// 왼발로 누르는 경우
				ndp[x][r] = min(ndp[x][r], dp[l][r] + cost[l][x]);
			}
		}

		memcpy(dp, ndp, sizeof(dp)); // -> 배열 특수화 -> SIMD 연산 최적화
		// swap(dp, ndp); -> 원소 단위 스왑 -> 더 느려 -> RAW 배열이라 포인터가 아님
		// -> 만약 vector 컨테이너 같은 컨테이너였으면? -> O(1) 이지 -> 내부 포인터만 교체
	}

	int answer = *min_element(&dp[0][0], &dp[0][0] + LAST * LAST);
	cout << answer << '\n';
	return 0;
}
#pragma endregion


#pragma region 오답 -> 그리디 풀이 예외 있음
//// 매순간 최선의 선택을 하는 그리디 문제 + 구현
//// 1. 현재 위치 -> 다른 위치로 이동하는 비용테이블을 정적으로 정의한다.
//// 2. 왼발, 오른발 두개의 발 위치에 따라 다음 위치로 이동하는 비용 테이블을 참조해 더 작은 값으로 이동을 수행한다.
//// 3. 사용한 비용은 answer에 추가한다.

//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int l{ 0 }, r{ 0 };
//	int answer{ 0 };
//	while (true)
//	{
//		int input;
//		cin >> input;
//		if (0 == input)
//			break;
//
//		if (cost[l][input] <= cost[r][input])
//		{
//			answer += cost[l][input];
//			l = input;
//		}
//		else
//		{
//			answer += cost[r][input];
//			r = input;
//		}
//	}
//
//	cout << answer << '\n';
//	return 0;
//}
#pragma endregion
