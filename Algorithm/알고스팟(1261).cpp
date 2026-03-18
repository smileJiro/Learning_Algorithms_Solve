#include <bits/stdc++.h>
using namespace std;


#pragma region 다익스트라 풀이
// 다익스트라로 푸는데 간선 가중치가 0인지 1인지 인거임 
// 간선 가중치가 0인 간선과 1인 간선만 존재하는 것 결국 간선 가중치가 낮은게 -> 벽을 가장 안부순 경우임 
//constexpr int INF = 1e9;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int N, M; // 1 ~ 100
//int board[101][101];
//int dist[101][101]; // 시작 노드 -> 각 노드 까지의 최단 거리 
//using Node = tuple<int, int, int>; // cost, y, x
//bool OOB(int y, int x)
//{
//	return y < 0 || y >= N || x < 0 || x >= M;
//}
//void Dijkstra(int startY, int startX)
//{
//	fill(&dist[0][0], &dist[0][0] + 101 * 101, INF);
//
//	priority_queue<Node, vector<Node>, greater<Node>> pq;
//	pq.emplace(0, startY, startX);
//	dist[startY][startX] = 0;
//
//	while (!pq.empty())
//	{
//		auto [c, y, x] = pq.top(); pq.pop();
//		if (c > dist[y][x]) // 이미 최단 경로가 갱신된 노드
//			continue;
//
//		if (y == N - 1 && x == M - 1) // 탈출 조건
//		{
//			cout << c << '\n';
//			return;
//		}
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (OOB(ny, nx))
//				continue;
//
//			int edgeWeight = board[ny][nx]; // 노드의 값 자체가 간선 가중치
//			if (dist[ny][nx] > dist[y][x] + edgeWeight)
//			{
//				dist[ny][nx] = dist[y][x] + edgeWeight;
//
//				pq.emplace(dist[ny][nx], ny, nx);
//			}
//		}
//	}
//
//}
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> M >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		string line;
//		cin >> line;
//		for (int j = 0; j < M; ++j)
//		{
//			board[i][j] = line[j] - '0';
//		}
//	}
//
//	Dijkstra(0, 0);
//	return 0;
//}
#pragma endregion


#pragma region 0-1 BFS 풀이
// deque 사용
// 가중치가 0이면 push_front, 1이면 push_back
using Pos = pair<int, int>; // y, x
constexpr int INF = 1e9;
constexpr int MAX = 100;

int N, M;
int board[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool OOB(int y, int x)
{
    return y < 0 || y >= N || x < 0 || x >= M;
}

void ZeroOneBFS(int startY, int startX)
{
    fill(&dist[0][0], &dist[0][0] + (MAX + 1) * (MAX + 1), INF);

    deque<Pos> dq;
    dq.emplace_front(startY, startX);
    dist[startY][startX] = 0;

    while (!dq.empty())
    {
        auto [y, x] = dq.front(); dq.pop_front();

        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (OOB(ny, nx))
                continue;

            int edgeWeight = board[ny][nx];
            if (dist[ny][nx] <= dist[y][x] + edgeWeight)
                continue;

            dist[ny][nx] = dist[y][x] + edgeWeight;


            // 0-1 BFS 핵심 가중치가 0 이면 front, 1이면 back
            if (edgeWeight == 0)
                dq.emplace_front(ny, nx);
            else
                dq.emplace_back(ny, nx);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 0; i < N; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; ++j)
            board[i][j] = line[j] - '0';
    }

    ZeroOneBFS(0, 0);
    cout << dist[N - 1][M - 1] << '\n';
    return 0;
}
#pragma endregion
