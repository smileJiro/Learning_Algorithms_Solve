#include <bits/stdc++.h>
using namespace std;


int K;
int V, E;
enum COLOR { NONE, R, B };
bool BFS(const vector<vector<int>>& graph, vector<COLOR>& colors, int start)
{
	using Node = pair<COLOR, int>; // 굳이 color 안넣어도 돼 그냥 q<int>로 하는게
	queue<Node> q;

	colors[start] = R;
	q.emplace(colors[start], start);

	while (!q.empty())
	{
		auto [color, cur] = q.front(); q.pop();

		for (int adj : graph[cur])
		{
			// 1. 이웃 컬러 == 내 컬러 -> 모순 -> 이분 그래프 X 
			if (NONE != colors[adj])
			{
				if (colors[adj] == color)
					return false;
				else
					continue;
			}

			colors[adj] = (color == R ? B : R);
			q.emplace(colors[adj], adj);
		}
	}

	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;

	while (K--)
	{
		cin >> V >> E;
		vector<vector<int>> graph(V + 1);
		for (int i = 0; i < E; ++i)
		{
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		vector<COLOR> colors(V + 1, NONE);
		bool isBipartiteGraph = true;
		for (int i = 1; i < V + 1; ++i) // 연결 그래프라 한적이 없음, 
		{
			if (colors[i] != NONE)
				continue;

			if (!BFS(graph, colors, i))
			{
				isBipartiteGraph = false;
				break;
			}
		}

		if (isBipartiteGraph)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

	}

	return 0;
}
// Bipartite Graph
// 인접한 노드의 색을 다르게 칠할수있는 그래프

