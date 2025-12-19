#include <bits/stdc++.h>
using namespace std;
constexpr int WhiteWidth = 100;
constexpr int BlackWidth = 10;

bool Board[WhiteWidth][WhiteWidth];
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	int Answer = 0;
	for (int i = 0; i < N; ++i)
	{
		int y, x;
		cin >> y >> x;

		for (int i = y; i < y + BlackWidth; ++i)
		{
			for (int j = x; j < x + BlackWidth; ++j)
			{
				if (!Board[i][j])
				{
					++Answer;
					Board[i][j] = true;
				}
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}