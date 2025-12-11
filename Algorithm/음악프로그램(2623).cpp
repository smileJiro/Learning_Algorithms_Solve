#include <bits/stdc++.h>
using namespace std;

int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// input
	cin >> N >> M;
	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1, 0);
	for (int i = 0; i < M; ++i)
	{
		int K;
		cin >> K;
		vector<int> nums(K);
		for (int j = 0; j < K; ++j)
		{
			cin >> nums[j];

			if (0 >= j)
				continue;

			int start = nums[j - 1];
			int end = nums[j];
			graph[start].push_back(end);
			indegree[end] += 1;
		}
	}

	// topology sort
	queue<int> q;
	for (int i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	vector<int> answer;
	while (!q.empty())
	{
		int idx = q.front(); q.pop();
		answer.push_back(idx);

		for (int adj : graph[idx])
		{
			indegree[adj] -= 1; // 진입 차수 감소(간선 제거)

			if (indegree[adj] == 0)
				q.push(adj);
		}
	}

	// result
	if (answer.size() < N) 
		cout << 0 << '\n';
	else
	{
		for (int i : answer)
			cout << i << '\n';
	}

	return 0;
}