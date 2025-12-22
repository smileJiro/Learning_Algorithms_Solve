#include <bits/stdc++.h>
using namespace std;
int R, C, N;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool OOB(int y, int x)
{
	return 0 > y || 0 > x || R <= y || C <= x;
}

void Explode(const vector<vector<char>>& src, vector<vector<char>>& out)
{
	vector<vector<char>> result(R, vector<char>(C, 'O'));
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (src[i][j] == 'O')
			{
				result[i][j] = '.';
				for (int d = 0; d < 4; ++d)
				{
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (!OOB(ny, nx))
					{
						result[ny][nx] = '.';
					}
				}
			}
		}
	}

	out.swap(result);
}

void RenderBoard(vector<vector<char>>& board)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> N;
	vector<vector<char>> allBomberBoard(R, vector<char>(C, 'O'));
	// 1. Even
	if (!(N % 2))
	{
		RenderBoard(allBomberBoard);
		return 0 ;
	}
	

	vector<vector<char>> board(R, vector<char>(C, 0));
	for(int i = 0; i < R; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; ++j)
		{
			board[i][j] = str[j];
		}
	}

	// 2. N == 1 
	if (N == 1)
	{
		RenderBoard(board);
		return 0;
	}

	// 3.  N != 1, Odd
	vector<vector<char>> E1, E2;
	Explode(board, E1);
	Explode(E1, E2);

	if ((N % 4) == 3)
	{
		RenderBoard(E1);
	}
	else
	{
		RenderBoard(E2);

#pragma region RenderBoard(board) ¹Ý·Ê
		// 3 3 5
		//...
		//OO.
		//...
#pragma endregion
	}
	
	return 0;
}