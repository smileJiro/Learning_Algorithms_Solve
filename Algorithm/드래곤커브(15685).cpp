#include <bits/stdc++.h>

using namespace std;

using Pos = pair<int, int>; // y, x
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int board[101][101];
int N;
Pos Rotation(Pos origin, Pos pivot)
{
	// 1. (원점으로 이동)
	Pos rotation{ origin.first - pivot.first, origin.second - pivot.second };
	// 2. CW 90도 회전
	rotation = { rotation.second, -rotation.first }; // {y, x} -> {x, -y}
	// 3. 다시 pivot 반영
	rotation = { rotation.first + pivot.first, rotation.second + pivot.second };
	return rotation;
}

void Compute_DragonCurve(int y, int x, int d, int g)
{
	// 1. 드래곤 커브를 만든다.
	vector<Pos> dragonCurve;
	dragonCurve.emplace_back(y,x); // 시작 노드
	board[y][x] = 1;
	dragonCurve.emplace_back(y + dy[d], x + dx[d]); // 방향에 따른 두번째 Pos (0세대 커브)
	board[y + dy[d]][x + dx[d]] = 1;

	for (int i = 0; i < g; ++i)
	{
		Pos pivot = dragonCurve.back();
		int size = dragonCurve.size();
		for (int j = size - 2; j >= 0; --j) // pivot은 돌릴필요 없다.
		{
			Pos cur = dragonCurve[j];
			Pos rotation = Rotation(cur, pivot);
			dragonCurve.emplace_back(rotation.first, rotation.second);

			// 2. board에 체크한다.
			board[rotation.first][rotation.second] = 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		Compute_DragonCurve(y, x, d, g);
	}


	// 감싸는 부분 검사
	int answer = 0;
	for (int i = 0; i < 101 - 1; ++i)
	{
		for (int j = 0; j < 101 - 1; ++j)
		{
			if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
				++answer;
		}
	}
	cout << answer << '\n';

	return 0;
}