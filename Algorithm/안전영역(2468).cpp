#include <bits/stdc++.h>
using namespace std;

using Pos = pair<int, int>;
int N; // 2 ~ 100
int board[101][101];
int visited[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool OOB(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}
void BFS(int rainHeight, int startY, int startX) // visited check 
{

	queue<Pos> q;
	q.emplace(startY, startX);
	visited[startY][startX] = 1;

	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!OOB(ny, nx) && rainHeight < board[ny][nx] && !visited[ny][nx])
			{
				q.emplace(ny, nx);
				visited[ny][nx] = 1;
			}
		}
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	int maxHeight = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			maxHeight = max(maxHeight, board[i][j]);
		}
	}

	int maxSafeArea = 0;
	for (int rain = 0; rain < maxHeight; ++rain)
	{
		int safeAreaCount = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (rain < board[i][j] && !visited[i][j])
				{
					safeAreaCount += 1; // counting 
					BFS(rain, i, j);
				}
			}
		}

		maxSafeArea = max(maxSafeArea, safeAreaCount);
	}

	cout << maxSafeArea << '\n';
	return 0;
}

// 1. bfs 돌리면서 visited 체크한다.
// 2. 외부에서 bfs 결과를 반환받아서 카운팅을 한다. -> 안전 영역인지 아닌지
// bfs == 안전 영역 인지 아닌지 검사, visited 체크
// 3. 이걸 비의 양에 따라 반복을 수행해야해 -> 높이의 범위 1 ~ 100  -> max 값 체크하고 해당 값부터 안전영역 검사

