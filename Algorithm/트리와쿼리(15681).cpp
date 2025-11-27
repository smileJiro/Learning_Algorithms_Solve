#include <bits/stdc++.h>
using namespace std;
int N, R, Q;

void dfs(vector<vector<int>>& graph, vector<int>& answer, int root)
{
	answer[root] += 1;             // 서브트리 노드의 수에 포함

	for (int adj : graph[root])
	{
		if (answer[adj] != 0)      // answer != 0 라면, 방문 노드(부모)로 본다.
			continue;

		dfs(graph, answer, adj);
		answer[root] += answer[adj];
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> R >> Q;


	int s{}, e{};
	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> s >> e;
		graph[s].push_back(e);     // 가중치X, 무방향
		graph[e].push_back(s);
	}

	vector<int> answer(N + 1, 0);  // 서브트리 노드의 수를 계산 
	dfs(graph, answer, R);


	vector<int> query(Q);
	for (int i = 0; i < Q; ++i)
		cin >> query[i];

	for (int q : query)
		cout << answer[q] << '\n';

	return 0;
}