#include <bits/stdc++.h>

using namespace std;

int N;
bool board[7000][7000];
void Recursive(int num)
{
	if (num == 1)
		return;

	Recursive(num / 3);

	int interval = num / 3;
	// 붙여넣을 인덱스 영역 설정
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 1 && j == 1)
				continue;


			// 복사본 찍기 로직
			for (int copyRow = 0; copyRow < interval; ++copyRow)
			{
				for (int copyCol = 0; copyCol < interval; ++copyCol)
				{
					board[i * interval + copyRow][j * interval + copyCol] = board[copyRow][copyCol];
				}
			}


		}
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	board[0][0] = 1;
	Recursive(N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}