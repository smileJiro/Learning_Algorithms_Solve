#include <bits/stdc++.h>

using namespace std;
using P = pair<int, int>; //  y, x

int board[22][22];
int visited[22][22];
int N;
int dy[] = { -1, 0, 0, 1 }; // 상, 좌, 우, 하
int dx[] = { 0, -1, 1, 0 };

struct EatResult
{
public:
	EatResult()
	{

	}
	EatResult(int _dist, int _y, int _x)
		: dist(_dist), y(_y), x(_x)
	{

	}
	int dist{-1};
	int y{-1}, x{-1};
};
bool OOB(int y, int x)
{
	return y < 0 || y >= N || x < 0 || x >= N;
}
bool BFS(int sy, int sx, int sharkLevel, EatResult& outResult)
{
	queue<P> q;
	fill(&visited[0][0], &visited[0][0] + 22 * 22, -1);
	q.emplace(sy, sx);
	visited[sy][sx] = 0;
	board[sy][sx] = 0;
	int minDist = 1e9;
	int targetY{N}, targetX{N};
	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();
		if (minDist < visited[y][x]) // 조기 종료 조건
			break;

		if (board[y][x] && (board[y][x] < sharkLevel) && minDist >= visited[y][x]) // 먹을 수 있는 물고기
		{
			minDist = visited[y][x];
			if (targetY > y || (targetY == y && targetX > x))
			{
				targetY = y;
				targetX = x;
				continue;
			}
		}

		for (int i = 0; i < 4; ++i) // bfs 탐색
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (OOB(ny, nx))
				continue;
			if (visited[ny][nx] != -1)
				continue;
			if (board[ny][nx] > sharkLevel)
				continue;

			q.emplace(ny, nx);
			visited[ny][nx] = visited[y][x] + 1;
		}
	}

	// 결과 정산
	if (minDist != 1e9)
	{
		outResult.dist = minDist;
		outResult.y = targetY;
		outResult.x = targetX;
		return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	int sy, sx;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				sy = i;
				sx = j;
			}
		}
	}

	int answer = 0;
	int sharkLevel = 2;
	int cnt = 0;
	while (true)
	{
		EatResult ret;
		if (BFS(sy, sx, sharkLevel, ret))
		{
			answer += ret.dist;
			sy = ret.y;
			sx = ret.x;
			board[sy][sx] = 0;
			++cnt;
			if (sharkLevel <= cnt)
			{
				++sharkLevel;
				cnt = 0;
			}
		}
		else
			break;
		
	}

	cout << answer << '\n';
	return 0;
}
