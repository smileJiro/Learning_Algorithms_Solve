#include <bits/stdc++.h>

using namespace std;
using Edge = tuple<int, int, int>; // cost, start, end
// MST 구현 문제로 보인다. -> 음수 간선 있으나 상관 없다. -> Kruskal

int V, E;
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
	cin >> V >> E;

	vector<Edge> edges;
	vector<int> rootTable(V + 1);
	for (int i = 0; i <= V; ++i)
		rootTable[i] = i;

	edges.reserve(E);
	for (int i = 0; i < E; ++i)
	{
		int c, s, e;
		cin >> s >> e >> c;
		edges.emplace_back(c, s, e);
	}
	sort(edges.begin(), edges.end());

	long long  answer = 0;
	for (auto& [c, s, e] : edges)
	{
		if (IsCycle(rootTable, s, e))
			continue;

		AddEdge(rootTable, s, e);
		answer += (long long)c;
	}

	cout << answer << '\n';
	return 0;
}

#pragma region tuple get example
/*vector<Edge> edges(E);
for (int i = 0; i < E; ++i)
{
	int c, s, e;
	cin >> c >> s >> e;
	get<0>(edges[i]) = c;
	get<1>(edges[i]) = s;
	get<2>(edges[i]) = e;
}*/
#pragma endregion