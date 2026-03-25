#include <bits/stdc++.h>
using namespace std;



int N, M;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool OOB(int y, int x)
{
	return y >= N || y < 0 || x >= M || x < 0;
}
void BFS(const vector<vector<int>>& cur, vector<vector<int>>& out, vector<vector<int>>& visited, int startY, int startX)
{

	using Pos = pair<int, int>; // y, x
	queue<Pos> q;
	q.emplace(startY, startX);
	visited[startY][startX] = 1;

	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (OOB(ny, nx))
				continue;

			if (cur[ny][nx] == 0)
			{
				out[y][x] = max(0, out[y][x] - 1);
			}
				
			else
			{
				if (visited[ny][nx])
					continue;

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

	cin >> N >> M;


	vector<vector<int>> cur(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> cur[i][j];
		}
	}

	vector<vector<int>> next = cur;
	vector<vector<int>> visited(N, vector<int>(M, 0));
	int answer = 0;
	while (true)
	{
		if (cur.empty())
			return 0;

		for (auto& row : visited)
			fill(row.begin(), row.end(), 0);

		// 1 . bfs 돌리면서 out 보드 업데이트 
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (cur[i][j] == 0)
					continue;
				
				if (visited[i][j] == 0)
				{
					if (++count == 2)
					{
						// 빙산 두동강 -> 종료임
						cout << answer << '\n';
						return 0 ;
					}
					BFS(cur, next, visited, i, j);
				}
				
			}
		}

		if (count == 0) // 0 예외처리 안해서 시간초과였네
		{
			cout << 0 << '\n';
			return 0;
		}

		cur = next;
		
		++answer;
	}

	return 0;
}