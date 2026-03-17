#include <bits/stdc++.h>

using namespace std;


int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	enum { R, G ,B };
	constexpr int INF = 1e9;
	vector<vector<int>> houses(N + 1, vector<int>(3, 0));

	for (int i = 1; i <= N; ++i)
	{
		cin >> houses[i][R] >> houses[i][G] >> houses[i][B];
	}

	vector<vector<int>> dp(N + 1, vector<int>(3, INF));
	dp[0] = {0,0,0};
	for (int i = 1; i <= N; ++i)
	{
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + houses[i][R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + houses[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + houses[i][B];
	}

	cout << *min_element(dp[N].begin(), dp[N].end()) << '\n';
	return 0;
}