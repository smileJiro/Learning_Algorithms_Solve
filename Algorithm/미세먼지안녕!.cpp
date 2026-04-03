#include <bits/stdc++.h>

using namespace std;

using Pos = pair<int, int>; // y, x
int R, C, T;

Pos airCleaner[2] = { {0,0}, {0,0} };
int board[51][51];
int newBoard[51][51];
int cwY[] = {-1, 0, 1, 0};
int cwX[] = {0, 1, 0, -1};
int ccwY[] = { 1, 0, -1, 0 };
int ccwX[] = { 0, 1, 0, -1 };

bool OOB(Pos lt, Pos rb, int y, int x)
{
	return y > rb.first || y < lt.first || x > rb.second || x < lt.second;
}

void Spread()
{
	memcpy(newBoard, board, sizeof(board));
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] <= 0)
				continue;

			int spreadValue = board[i][j] / 5;
			int count = 0;
			for (int d = 0; d < 4; ++d)
			{
				int ny = i + cwY[d];
				int nx = j + cwX[d];
				if (OOB({ 0,0 }, {R - 1, C - 1}, ny, nx) || board[ny][nx] == -1)
					continue;

				newBoard[ny][nx] += spreadValue;
				++count;
			}
			newBoard[i][j] -= spreadValue * count;
		}
	}
	memcpy(board, newBoard, sizeof(board));
	int a = 0;
}

void Clean()
{
	memcpy(newBoard, board, sizeof(board));
	
	Pos lt = { 0, 0 };
	Pos rb = { airCleaner[0].first, C - 1 };
	int d = 0;
	
	Pos cur = { airCleaner[0].first, airCleaner[0].second };
	while (true)
	{
		Pos newPos = { cur.first + cwY[d], cur.second + cwX[d] };
		if (newPos == airCleaner[0]) // 탈출 조건
			break;

		if (OOB(lt, rb, newPos.first, newPos.second))
		{
			++d;
			newPos = { cur.first + cwY[d], cur.second + cwX[d] };
		}

		newBoard[newPos.first][newPos.second] -= board[newPos.first][newPos.second];
		if (-1 != board[cur.first][cur.second]) // 시작 노드 아닐때
		{
			newBoard[cur.first][cur.second] += board[newPos.first][newPos.second];
		}
		cur = newPos;
	}

	lt = { airCleaner[1].first, 0};
	rb = { R - 1, C - 1 };
	d = 0;

	cur = { airCleaner[1].first, airCleaner[1].second };
	while (true)
	{
		Pos newPos = { cur.first + ccwY[d], cur.second + ccwX[d] };
		if (newPos == airCleaner[1]) // 탈출 조건
			break;

		if (OOB(lt, rb, newPos.first, newPos.second))
		{
			++d;
			newPos = { cur.first + ccwY[d], cur.second + ccwX[d] };
		}

		newBoard[newPos.first][newPos.second] -= board[newPos.first][newPos.second];
		if (-1 != board[cur.first][cur.second]) // 시작 노드 아닐때
		{
			newBoard[cur.first][cur.second] += board[newPos.first][newPos.second];
		}
		cur = newPos;
	}

	memcpy(board, newBoard, sizeof(board));
	int a = 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> T;

	int airIndex = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == -1)
			{
				airCleaner[airIndex++] = { i, j };
			}
		}
	}
	
	while (T--)
	{
		// 1. 미먼 확산 시뮬레이션
		Spread();
		// 2. 공기청정기 바람 흡입 시뮬레이션 
		Clean();

		board;
		int a;
	}

	int sum = 2;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			sum += board[i][j];
		}
	}

	cout << sum << '\n';
	return 0;
}