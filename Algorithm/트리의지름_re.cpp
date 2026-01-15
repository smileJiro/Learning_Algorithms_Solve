#include <bits/stdc++.h>

using namespace std;
using P = pair<int, int>; // cost, child
/*
	* 1. 루트 노드에서 가장 먼 노드 A를 찾는다.
	* 2. A에서 또 가장 먼 노드를 B를 찾는다.
	* 3. 이때 A에서 B 까지의 거리가 트리의 지름이다.
*/

void dfs(vector<vector<P>>& graph, vector<int>& visited, int curNode, int curCost, int& outFarCost, int& outFarNode)
{
	visited[curNode] = 1;
	if (outFarCost < curCost)
	{
		outFarCost = curCost;
		outFarNode = curNode;
	}

	for (auto& [adjCost, adjNode] : graph[curNode])
	{
		if (visited[adjNode] == 1)
			continue;

		dfs(graph, visited, adjNode, curCost + adjCost, outFarCost, outFarNode);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	vector<vector<P>> graph(N + 1);
	vector<int> visited(N + 1, 0);
	for (int i = 0; i < N - 1; ++i)
	{
		int parent, child, cost;
		cin >> parent >> child >> cost;

		graph[parent].emplace_back(cost, child);
		graph[child].emplace_back(cost, parent);
	}

	
	int farCost{ 0 }, farNode{ 0 };
	dfs(graph, visited, 1, 0, farCost, farNode);

	int answer{ 0 };
	fill(visited.begin(), visited.end(), 0);
	dfs(graph, visited, farNode, 0, answer, farNode);
	
	cout << answer << '\n';
	return 0;
}