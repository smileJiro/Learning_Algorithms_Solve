#include <bits/stdc++.h>

using namespace std;

// 2초 -> 약 1억번
// MST 문제 같네
int N, M;
struct Edge
{
	int start{}, end{};
	int cost{};
};

int FindRoot(vector<int>& rootTable, int node)
{
	if (rootTable[node] == node)
		return node;

	return rootTable[node] = FindRoot(rootTable, rootTable[node]);
}
void AddEdge(vector<int>& rootTable, int node1, int node2)
{
	int root1 = FindRoot(rootTable, node1);
	int root2 = FindRoot(rootTable, node2);

	if (root1 < root2)
		rootTable[root2] = root1;
	else
		rootTable[root1] = root2;
}
bool IsCycle(vector<int>& rootTable, int node1, int node2)
{
	return FindRoot(rootTable, node1) == FindRoot(rootTable, node2);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	
	vector<int> rootTable(N + 1);
	for (int i = 0; i <= N; ++i)
		rootTable[i] = i;

	vector<Edge> edgeList(M);
	for (int i = 0; i < M; ++i)
		cin >> edgeList[i].start >> edgeList[i].end >> edgeList[i].cost;

	sort(edgeList.begin(), edgeList.end(), [](Edge& a, Edge& b) {
		return a.cost < b.cost;
		});

	int answer = 0;
	int bigCost = 0;
	for (const auto& [start, end, cost] : edgeList)
	{
		if (IsCycle(rootTable, start, end))
			continue;

		//cout << "start: " << start << " end: " << end << '\n';
		answer += cost;
		bigCost = cost;
		AddEdge(rootTable, start, end);
	}

	// 가장 비용이 큰 마지막 길을 자르면 돼 -> 두 마을로 나누는 거니까
	cout << answer - bigCost << '\n';
	return 0;
}