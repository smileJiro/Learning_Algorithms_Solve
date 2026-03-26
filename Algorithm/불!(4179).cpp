#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>; // turn, y, x;
using Pos = pair<int, int>;
int N, M;
int board[1001][1001];
int fireBoard[1001][1001];
int jihoonBoard[1001][1001];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool OOB(int y, int x)
{
	return y >= N || y < 0 || x >= M || x < 0;
}
void FireBFS(queue<Pos>& q)
{
	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (OOB(ny, nx) || board[ny][nx] == '#' || fireBoard[ny][nx] != -1)
				continue;

			fireBoard[ny][nx] = fireBoard[y][x] + 1;
			q.emplace(ny, nx);
		}
	}
}

void JihoonBFS(int startY, int startX)
{
	queue<Pos> q;
	q.emplace(startY, startX);
	jihoonBoard[startY][startX] = 0;

	while (!q.empty())
	{
		auto [y, x] = q.front(); q.pop();

		for (int d = 0; d < 4; ++d)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (OOB(ny, nx))
			{
				cout << jihoonBoard[y][x] + 1 << '\n';
				return;
			}
			if (board[ny][nx] == '#') continue;
			if (jihoonBoard[ny][nx] != -1) continue;

			if (fireBoard[ny][nx] != -1 && fireBoard[ny][nx] <= jihoonBoard[y][x] + 1)
				continue;

			jihoonBoard[ny][nx] = jihoonBoard[y][x] + 1;
			q.emplace(ny, nx);
		}
	}

	cout << "IMPOSSIBLE" << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	queue<Pos> fire;
	int startY = -1, startX = -1;

	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = s[j];
			fireBoard[i][j] = -1;
			jihoonBoard[i][j] = -1;

			if (board[i][j] == 'F')
			{
				fire.emplace(i, j);
				fireBoard[i][j] = 0;
			}
			else if (board[i][j] == 'J')
			{
				startY = i;
				startX = j;
			}
		}
	}

	FireBFS(fire);
	JihoonBFS(startY, startX);

	return 0;
}
