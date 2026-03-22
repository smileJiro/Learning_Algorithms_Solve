#include <bits/stdc++.h>
using namespace std;


#pragma region ���ͽ�Ʈ�� Ǯ��
// ���ͽ�Ʈ���? Ǫ�µ� ���� ����ġ�� 0���� 1���� �ΰ��� 
// ���� ����ġ�� 0�� ������ 1�� ������ �����ϴ� �� �ᱹ ���� ����ġ�� ������ -> ���� ���� �Ⱥμ� �����? 
//constexpr int INF = 1e9;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1, 0, -1 };
//
//int N, M; // 1 ~ 100
//int board[101][101];
//int dist[101][101]; // ���� ���? -> �� ���? ������ �ִ� �Ÿ� 
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
//		if (c > dist[y][x]) // �̹� �ִ� ��ΰ�? ���ŵ� ���?
//			continue;
//
//		if (y == N - 1 && x == M - 1) // Ż�� ����
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
//			int edgeWeight = board[ny][nx]; // �����? �� ��ü�� ���� ����ġ
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


#pragma region 0-1 BFS Ǯ��
// deque ���?
// ����ġ�� 0�̸� push_front, 1�̸� push_back
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


            // 0-1 BFS �ٽ� ����ġ�� 0 �̸� front, 1�̸� back
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
