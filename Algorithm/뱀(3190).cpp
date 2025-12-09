#include<bits/stdc++.h>
using namespace std;

using P = pair<int, char>;
using IDX = pair<int, int>; 
int N, K, L;
int board[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int playtime = 0;
int dir = 1;

// 게임 종료 조건
bool OOB(const int y, const int x)
{
	return y <= 0 || x <= 0 || y > N || x > N;
}

bool CollisionSelf(const deque<IDX>& snake, const int y, const int x)
{
	for (auto& [r, c] : snake)
	{
		if (y == r && x == c)
			return true;
	}

	return false;
}

// 사과 확인
bool CheckApple(const int y, const int x)
{
	bool ret = board[y][x];
	if (ret)
		board[y][x] = 0;
	return ret;
}

// 방향 전환 쿼리 확인
void CheckDirectionQuery(queue<P>& query)
{
	if (!query.empty())
	{
		auto& [t, d] = query.front();
		if (t == playtime)
		{
			query.pop();
			if (d == 'D')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int y, x;
		cin >> y >> x;
		board[y][x] = 1;
 	}
	
	cin >> L;
	queue<P> query;
	for (int i = 0; i < L; ++i)
	{
		int t;
		char d;
		cin >> t >> d;
		query.emplace(t, d);
	}

	deque<IDX> snake;
	snake.emplace_front(1,1);
	while (true)
	{
		++playtime;
		auto& [y, x] = snake.front();

		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (OOB(ny, nx) || CollisionSelf(snake, ny, nx))
			break;

		snake.emplace_front(ny, nx);

		if (!CheckApple(ny, nx))
			snake.pop_back();

		CheckDirectionQuery(query);
	}
	cout << playtime << '\n';


	return 0;
}