#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>; // y, x

int N, L, R;

class nae
{

};
int board[52][52];
bool visited[52][52];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool OOB(int r, int c)
{
	return r < 0 || r >= N || c < 0 || c >= N;
}

bool CanOpen(int y, int x) 
{
	for (int i = 0; i < 4; ++i) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (OOB(ny, nx)) continue;
		int diff = abs(board[y][x] - board[ny][nx]);
		if (diff >= L && diff <= R)
			return true;
	}
	return false;
}

bool BFS(int r, int c)
{
	bool isOpened = false;

	queue<P> q;
	vector<P> updates;
	q.emplace(r,c);
	updates.emplace_back(r, c);
	visited[r][c] = true;

	int total = board[r][c];
	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (OOB(ny, nx))
				continue;
			if (visited[ny][nx])
				continue;

			int diff = abs(board[ny][nx] - board[y][x]);
			if (diff >= L && diff <= R)
			{
				// 국경 open
				isOpened = true;
				q.emplace(ny, nx);
				updates.emplace_back(ny, nx);
				visited[ny][nx] = true;
				total += board[ny][nx];
			}
		}
	}

	if (isOpened)
	{
		int aver = total / updates.size();
		for (auto& [y, x] : updates)
		{
			board[y][x] = aver;
		}
	}

	return isOpened;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}


	int cnt = 0;
	while (true)
	{
		// 국경 개방 여부 검사
		memset(visited, 0, sizeof(visited));
		bool isOpened = false;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j] == true)
					continue;

				// 현재 국가가 개방 가능성이 있는지 사전 체크 (496ms -> 72ms)
				if (!CanOpen(i, j)) 
				{
					visited[i][j] = true;
					continue;
				}

				isOpened |= BFS(i, j);
			}
		}

		// 이번 턴에 개방된 적이 없다면, 탈출
		if (false == isOpened)
		{
			break;
		}

		++cnt;
	}

	cout << cnt << '\n';
	return 0;
}