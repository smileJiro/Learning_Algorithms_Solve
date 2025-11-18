#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>; // y,x
int board[20][20];
enum DIR { RT, R, RB, B, LAST };
int dy[] = { -1, 0, 1, 1}; 
int dx[] = { 1, 1, 1, 0 }; 

bool OOB(int y, int x)
{
	return 0 >= y || 19 < y || 0 >= x || 19 < x;
}
void dfs(int y, int x, int dir, int type, int* outCount)
{
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (!OOB(ny, nx) && board[ny][nx] == type)
	{
		*outCount += 1;
		dfs(ny, nx, dir, type, outCount);
	}
}
bool IsFinished(int y, int x)
{
	int type = board[y][x];

	for(int dir = 0 ; dir < 4; ++dir)
	{
		// 반대 방향에 같은 색 돌이 있다면, 시작 돌 아닌 것으로 판정
		int ny = y - dy[dir];
		int nx = x - dx[dir];
		if (!OOB(ny, nx) && board[ny][nx] == type)
			continue;

		// 카운트 시작
		int count = 0;
		dfs(y, x, dir, type, &count);
		if (count == 4)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<P> black;
	vector<P> white;
	for (int i = 1; i < 20; ++i)
	{
		for (int j = 1; j < 20; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				black.emplace_back(i, j);
			else if (board[i][j] == 2)
				white.emplace_back(i, j);
		}
	}

	// black과 white 각각 검사 수행
	for (auto& [y, x] : black)
	{
		if (IsFinished(y, x))
		{
			cout << 1 << '\n';
			cout << y << ' ' << x << '\n';
			return 0;
		}
	}

	for (auto& [y, x] : white)
	{
		if (IsFinished(y, x))
		{
			cout << 2 << '\n';
			cout << y << ' ' << x << '\n';
			return 0;
		}
	}

	cout << 0 << '\n';

	return 0;
}

// 양방향 검사할 필요 없다.
// 4방향만 검사하되, 자기 자신이 가장 좌측 돌인지 검사하고, 가장 좌측 돌인게 판정되면 5목검사
// -> 이로인해 자연스럽게 6목 이상은 제외된다.


// 디버깅 노트
// 주요 로직에 문제가 없는데 계속 틀렸습니다가 떴었다.
// if (!OOB(ny, nx) && board[ny][nx] == type)
// continue; -> 이게 return false; 로 되어있었어서 다른 방향에 대한 검사를 못했던거야
