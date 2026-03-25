//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N, K; // 물품 수, 준서가 버틸수있는 무게
//// 현재 물건 집는 경우, 안집는경우
//// 집는 경우  -> dp[K - obj[j].first][j - 1] + obj[j].second;
//// 못집는 경우 -> dp[i][j - 1]
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> K;
//
//	using Obj = pair<int, int>; // w, v
//	vector<Obj> objects(N + 1, {0,0});
//	for (int i = 1; i <= N; ++i)
//	{
//		int W, V;
//		cin >> W >> V;
//
//		objects[i] = { W, V };
//	}
//
//	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
//	for (int i = 1; i <= K; ++i)
//	{
//		for (int j = 1; j <= N; ++j)
//		{
//			dp[i][j] = dp[i][j - 1];
//			if (0 <= i - objects[j].first) // 현재 물건을 담을수있는경우
//			{
//				dp[i][j] = max(dp[i][j], dp[i - objects[j].first][j - 1] + objects[j].second);
//			}			
//		}
//	}
//	cout << dp[K][N] << '\n';
//
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;


// 현재 물건 집는 경우, 안집는경우
// 경우가 이렇게 2개뿐이라면 0/1 Knapsack 쓸수있다. 1차원 dp
// dp 축을 최대 무게로 두고, item을 순회하면서 dp[K - i] 부터 역순으로 채운다.
// 현재 물건을 집는경우 dp[weight - w] + v
// 집지 않는 경우 dp[weight]
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    using Obj = pair<int, int>; // W, V
    vector<Obj> objects(N + 1);
    for (int i = 0; i < N; ++i)
    {
        cin >> objects[i].first >> objects[i].second;
    }

    vector<int> dp(K + 1, 0); // 무게 제한 축
    for (int i = 0; i < N; ++i) // 물건 전부 순회
    {
        int w = objects[i].first;
        int v = objects[i].second;

        // 0/1 Knapsack 이라 뒤에서 앞으로 

        for (int weight = K; weight >= w; --weight) // weight 최대무게부터 시작 
        {
            // 현재 무게
            dp[weight] = max(dp[weight], dp[weight - w] + v);
        }
    }

    cout << dp[K] << '\n';

	return 0;
}

// {3,7}, {5, 10}, { 2, 4 }

// 0, 0, 0, 7 ,7, 7, 7, 7, 7
// 0, 0, 0, 7, 7, 10, 10, 10, 17
// 0, 0, 4, 7, 7, 