#include <bits/stdc++.h>

using namespace std;

enum COLOR {R,G,B,LAST};
int N;
int cost[1002][LAST];
int dp[1002][LAST];
int answer = 1e9;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int startColor = 0; startColor < LAST; ++startColor)
	{
		for (int i = 0; i < 3; i++) 
		{
			if (i == startColor)
				dp[1][i] = cost[1][i];
			else
				dp[1][i] = 1e9; // 선택되면 안되니까 큰 값을 넣는거임
		}

		for (int i = 2; i <= N; ++i)
		{
			dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R];
			dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + cost[i][G];
			dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + cost[i][B];
		}

		for (int i = 0; i < 3; ++i)
		{
			if (i == startColor)
				continue;
			answer = min(answer, dp[N][i]);
		}
	}
	
	cout << answer << '\n';

	return 0;
}