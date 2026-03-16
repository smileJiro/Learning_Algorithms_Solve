#include <bits/stdc++.h>

using namespace std;

// time limit: 1sec
// memory limit: 512mb
// answer: 모든 트럭이 다리를 건너는 최단 시간

// params
// 1. truck list
// 2. brigde limit weight (L)
// 3. brigde distance (W) -> truck len == 1


// 이벤트 기반 시뮬레이션? -> 트럭 수만큼만 루프돌게 압축
int N, W, L;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> W >> L;

	vector<int> truckList(N);
	vector<int> outTime(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> truckList[i];

	int currentWeight = 0;
	int frontTruckIndex = 0;
	int lastEnterTime = 0;

	for (int i = 0; i < N; ++i)
	{
		int weightAvailableTime = 0;
		while (currentWeight + truckList[i] > L) // 무게 제한
		{
			weightAvailableTime = outTime[frontTruckIndex];
			currentWeight -= truckList[frontTruckIndex++];
		}

		currentWeight += truckList[i];

		int enterTime = max(lastEnterTime + 1, weightAvailableTime);
		outTime[i] = enterTime + W;
		lastEnterTime = enterTime;
	}

	cout << outTime.back() << '\n';
	return 0;
}