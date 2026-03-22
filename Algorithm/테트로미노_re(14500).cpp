#include <bits/stdc++.h>

using namespace std;
using Pos = pair<int, int>;

int N, M;
// // r: 2, c:3
// { 1, 2, 3 }
// { 4, 5, 6 }
// d[0][0] -> n[0][1]
// d[0][1] -> n[1][1]
// d[0][2] -> n[2][1]

// d[1][0] -> n[0][0]
// d[1][1] -> n[1][0]
// d[1][2] -> n[2][0]

// // d[i][j] -> n[j][r - i - 1];
// { 4, 1}
// { 5, 2}
// { 6, 3}
void DebugDraw(vector<vector<int>>& board)
{
    int n = (int)board.size();
    int m = (int)board[0].size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void Rotation(const vector<vector<int>>& origin, vector<vector<int>>& out) // CW
{
    if(origin.empty())
        return;

    int r = origin.size();
    int c = origin[0].size();

    out.resize(c, vector<int>(r));
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            out[j][r - i - 1] = origin[i][j];
        }
    }

}

int Get_Sum(const vector<vector<int>>& board, const vector<Pos>& tetromino)
{
    if(board.empty())
        return 0;

    int r = board.size();
    int c = board[0].size();
    
    int maxSum = 0;
    // 1. 보드를 순회
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            int sum = 0;
            bool bOOB = false;
            for(auto& [y, x] : tetromino)
            {
                int ny = y + i;
                int nx = x + j;
                if(ny >= r || ny < 0 || nx >= c || nx < 0)
                {
                    bOOB = true; 
                    break;
                }
                sum += board[ny][nx];
            }

            if(!bOOB) // 유효한 경우에만
            {
                maxSum = max(maxSum, sum);
            }
        }
    }

    return maxSum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    vector<vector<int>> origin(N , vector<int>(M, 0));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> origin[i][j];
        }
    }

    vector<vector<Pos>> tetrominos = {
    {{0,0}, {0,1}, {0,2}, {0,3}},  // I
    {{0,0}, {0,1}, {1,0}, {1,1}},  // O
    {{0,0}, {0,1}, {0,2}, {1,1}},  // T
    {{0,0}, {1,0}, {2,0}, {2,1}},  // L
    {{0,1}, {1,1}, {2,1}, {2,0}},  // flip L
    {{0,0}, {1,0}, {1,1}, {2,1}},  // S
    {{0,1}, {1,1}, {1,0}, {2,0}},  // flip S

    };

    vector<vector<int>> board = origin;
    int maxSum = 0;
    for(int r = 0; r < 4; ++r)
    {
        for(int i = 0; i < tetrominos.size(); ++i) 
        {
            maxSum = max(maxSum, Get_Sum(board, tetrominos[i]));
        }
        vector<vector<int>> rotation;
        Rotation(board, rotation);
        board = rotation;
    }

    cout << maxSum << '\n';
    return 0;
}