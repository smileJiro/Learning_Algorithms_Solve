// O(n^)까지 가능
// 가장 높은 기둥 인덱스를 저장
// 해당 인덱스 기준 좌측과 우측으로 나누어 가장 높은 높이 찾기
// 이떄 좌측은 0 부터 정순 , 우측은 size() -1 부터 역순 순회
// 만약 현재 최대 높이보다 높은 높이를 가진 기둥을 만났다면 answer에 너비 추가

#pragma region MyAnswer
#include <bits/stdc++.h>
using namespace std;
using STICK = pair<int, int>; // x, y
int N;
int answer = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<STICK> Sticks(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Sticks[i].first >> Sticks[i].second;
	}

	// x 좌표 기준으로 정렬
	sort(Sticks.begin(), Sticks.end());
	// y가 가장 높은 스틱 인덱스 저장
	int topIdx = max_element(Sticks.begin(), Sticks.end(), [](pair<int, int>& a, pair<int, int>& b) 
		{
			return a.second < b.second;
		}) - Sticks.begin();


	// 가장 높은 스틱 너비 추가
	answer += Sticks[topIdx].second;

	// left
	int maxX = Sticks[0].first;
	int maxY = Sticks[0].second;
	for (int i = 1; i <= topIdx; ++i)
	{
		auto [x, y] = Sticks[i];
		if (maxY <= y)
		{
			// 너비 계산
			int width = x - maxX;
			int height = maxY;
			answer += width * height;
			// max 값 업데이트
			maxX = x;
			maxY = y;
		}
	}

	// right
	maxX = Sticks[N - 1].first;
	maxY = Sticks[N - 1].second;
	for (int i = N - 2; i >= topIdx; --i)
	{
		auto [x, y] = Sticks[i];
		if (maxY <= y)
		{
			// 너비 계산
			int width = maxX - x;
			int height = maxY;
			answer += width * height;
			// max 값 업데이트
			maxX = x;
			maxY = y;
		}
	}

	cout << answer << '\n';
	return 0;
}
#pragma endregion

/* Debug Note */
// 기둥의 높이가 같은 경우에도 면적 계산을 해야하는데 안해서 문제가 있었음

// edge case input
// 2
// 4, 10
// 8, 10

// if (maxY < y) -> if (maxY <= y) 로 변경해서 해결