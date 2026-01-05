#include <bits/stdc++.h>

using namespace std;

/**
* 1. 위상 정렬 알고리즘을 사용 -> 자연스럽게 사이클이 없는 노드를 제거하며 순회
* 2. 사이클이 없는 노드의 개수를 카운팅
* 3. answer = 탐색한 노드 개수;
*/

int T;
int N;
void TopologySort(const vector<int>& graph, vector<int>& indegree)
{
	vector<int> result;
	result.reserve(N);

	queue<int> q;
	// 1. 진입 차수 0인 노드 전부 푸쉬
	for (int i = 1; i <= N; ++i)
	{
		if (0 == indegree[i])
			q.push(i);
	}

	// 2. 위상 정렬 수행
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		result.push_back(cur);

		int next = graph[cur];
		--indegree[next];
		if(0 == indegree[next])
			q.push(next);

	}

	// 3. 출력
	int answer = result.size();
	cout << answer << '\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	while (T--)
	{
		cin >> N;
		vector<int> graph(N + 1); // 진출차수 1개 고정 -> 인덱스: 노드 번호, 값: 이웃노드
		vector<int> indegree(N + 1, 0);

		for (int i = 1; i <= N; ++i)
		{
			cin >> graph[i];
			++indegree[graph[i]];
		}

		TopologySort(graph, indegree);
	}


	return 0;
}