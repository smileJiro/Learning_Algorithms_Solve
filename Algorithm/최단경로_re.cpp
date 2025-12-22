#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>; // cost, idx;
constexpr int INF = 1e9;
int V, E, K;
struct Adj
{
public:
	Adj(int i, int c)
		: Index(i), Cost(c)
	{}
public:
	int Index{}, Cost{};
};
void Dijkstra(const vector<vector<Adj>>& Graph, vector<int>& Dist, int Start)
{
	priority_queue<P, vector<P>, greater<P>> pq;
	Dist[Start] = 0;

	pq.emplace(Dist[Start], Start);
	while (!pq.empty())
	{
		auto [CurrentDist, CurrentIndex] = pq.top(); pq.pop();
		if (CurrentDist > Dist[CurrentIndex])
			continue;

		for (auto& [AdjIndex, AdjCost] : Graph[CurrentIndex])
		{
			if (Dist[CurrentIndex] + AdjCost < Dist[AdjIndex])
			{
				Dist[AdjIndex] = Dist[CurrentIndex] + AdjCost;
				pq.emplace(Dist[AdjIndex], AdjIndex);
			}
			
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E >> K;
	vector<vector<Adj>> Graph(V + 1);
	vector<int> Dist(V + 1, INF);
	int s, e, c;
	for (int i = 0; i < E; ++i)
	{
		cin >> s >> e >> c;
		Graph[s].emplace_back(e, c);
	}

	Dijkstra(Graph, Dist, K);

	for (int i = 1; i <= V; ++i)
	{
		if (Dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << Dist[i] << '\n';
	}
	return 0;
}