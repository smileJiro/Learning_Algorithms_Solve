#pragma region MyAnswer
#include <bits/stdc++.h>

using namespace std;

int N, M;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int board[52][52];
bool OOB(int y, int x)
{
	return 0 > y || N <= y || 0 > x || M <= x;
}

struct Robot
{
public:
	Robot(int r, int c, int d)
		:y(r)
		,x(c)
		,dir(d)
	{
		ComputeBackDir();
	}
public:
	void Rotation()
	{
		dir -= 1;
		if (dir < 0)
			dir += 4;

		ComputeBackDir();
	}
private:
	void ComputeBackDir()
	{
		backDir = (dir + 2) % 4;
	}

public:
	int y{}, x{};
	int dir{};
	int backDir{};
};

int Action(Robot& robot)
{
	int answer{};
	int cleaned[52][52] = { 0, };
	while (true)
	{
		if (!cleaned[robot.y][robot.x])
		{
			cleaned[robot.y][robot.x] = 1;
			++answer;
		}

		bool isCleaned = false;
		for (int i = 0; i < 4; ++i)
		{
			int ny = robot.y + dy[i];
			int nx = robot.x + dx[i];
			if (!OOB(ny, nx) && !cleaned[ny][nx] && !board[ny][nx])
			{
				isCleaned = true;
				break;
			}
		}

		if (isCleaned)
		{
			robot.Rotation();
			int ny = robot.y + dy[robot.dir];
			int nx = robot.x + dx[robot.dir];
			if (!OOB(ny, nx) && !cleaned[ny][nx] && !board[ny][nx])
			{
				robot.y = ny;
				robot.x = nx;
			}
		}
		else
		{
			int ny = robot.y + dy[robot.backDir];
			int nx = robot.x + dx[robot.backDir];
			if (!OOB(ny, nx) && !board[ny][nx])
			{
				robot.y = ny;
				robot.x = nx;
			}
			else
			{
				break;
			}
		}
	}

	return answer;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	
	int r{}, c{}, d{};
	cin >> r >> c >> d;
	Robot robot(r,c,d);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}
	cout << Action(robot) << '\n';

	return 0;
}
#pragma endregion

