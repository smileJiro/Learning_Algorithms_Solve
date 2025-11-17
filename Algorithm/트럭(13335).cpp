
#pragma region MyAnswer
//#include <bits/stdc++.h>
//using namespace std;
//int N, W, L;
//
//// table[t] : 시간 t에 다리 위에 존재하는 트럭들의 총 하중
//// 트럭이 time에 올라오면 [time, time+W) 구간 동안 하중을 더해줌
//constexpr int MAX = 1000 * 100 + 100 + 2; // N * W + W + 여유;
//int table[MAX];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> W >> L;
//	queue<int> q;
//	for (int i = 0; i < N; ++i)
//	{
//		int t;
//		cin >> t;
//		q.push(t);
//	}
//
//	int time = 0;
//	int answer = 0;
//	while (!q.empty())
//	{
//		++time;
//		int t = q.front();
//
//		if (t + table[time] <= L)
//		{
//			for (int i = time; i < time + W; ++i)
//			{
//				table[i] += t;
//			}
//			answer = time + W;
//			q.pop();
//		}
//
//	}
//
//	cout << answer << '\n';
//	return 0;
//}
#pragma endregion


#pragma region OtherAnswer
#include <bits/stdc++.h>
using namespace std;

int N, W, L;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> W >> L;

	vector<int> trucks(N);
	for (int i = 0; i < N; ++i)
		cin >> trucks[i];

	queue<int> bridge;
	int time{}, sum{}, idx{}; // 흐른 시간, 다리 위 총 무게, 다음에 올릴 트럭 인덱스
	
	// 최초에는 다리의 상태를 모두 0으로 초기화
	for (int i = 0; i < W; ++i)
		bridge.push(0);

	// 다리위에 아무것도 남지 않을 때까지 반복
	while (!bridge.empty())
	{
		++time;
		// 1. 한 칸 전진 후 맨 앞칸 pop
		sum -= bridge.front(); bridge.pop();

		// 2. 아직 다리에 올라오지 못한 트럭이 있다면
		if (idx < N) // idx == N - 1이 되어야 모든 트럭이 올라온 것
		{
			if (sum + trucks[idx] <= L)
			{
				// if. 트럭을 올릴 수 있다면
				bridge.push(trucks[idx]);
				sum += trucks[idx++];
			}
			else
			{
				// if. 무게 초과라면, 비어 있는 칸을 밀어 넣는다
				bridge.push(0);
			}
		}
		
	}

	cout << time << '\n';

	return 0;
}
#pragma endregion
