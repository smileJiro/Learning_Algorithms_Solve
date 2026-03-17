#include <bits/stdc++.h>

using namespace std;

int32_t dp[1001];
int32_t N;
int main()
{
	// i - 1 °³ + i - 2 °³ 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	dp[0] = 0; dp[1] = 1; dp[2] = 2;

	for (int32_t i = 3; i <= N; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[N] << '\n';

	return 0;
}