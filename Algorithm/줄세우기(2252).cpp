#include <bits/stdc++.h>
using namespace std;


int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	vector<vector<int>> graph(N + 1);
	vector<int> indegree(N + 1, 0);
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		indegree[e] += 1;
	}

	// Topology Sort
	queue<int> q;
	for (int i = 1; i <= N; ++i)
	{
		if (!indegree[i])
			q.push(i);
	}

	vector<int> answer;
	answer.reserve(N);
	while (!q.empty())
	{
		int idx = q.front(); q.pop();
		answer.push_back(idx);
		for (int adj : graph[idx])
		{
			indegree[adj] -= 1;

			if (!indegree[adj])
				q.push(adj);
		}
	}

	// Check Cycle
	if (answer.size() != N) // size < N ÀÎ °æ¿ì,
		cout << "Is Cycle!" << '\n';
	else
	{
		for (int idx : answer)
			cout << idx << ' ';

		cout << '\n';
	}
	return 0;
}