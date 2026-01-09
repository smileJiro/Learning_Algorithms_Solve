#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	vector<ll> p(N + 1);
	for (int i = 0; i < N; ++i)
	{
		ll r, c;
		cin >> r >> c;
		if (i == 0)
		{
			p[0] = r;
		}
		p[i + 1] = c;
	}

	constexpr ll INF = (1LL << 62);
	vector<vector<ll>> dp(N, vector<ll>(N, 0));

	for (int len = 2; len <= N; ++len)
	{
		for (int i = 0; i + len - 1 < N; ++i)
		{
			int j = i + len - 1;
			dp[i][j] = INF;

			for (int k = i; k < j; ++k)
			{
				// i ~ k 까지 비용 (dp[i][k])
				// (k + 1) ~ j 까지 비용 (dp[k + 1][j])
				// 이 두 결과 행렬을 곱하는 비용 (p[i] * p[k + 1] * p[j + 1])
				ll cost =	dp[i][k] + 
							dp[k + 1][j] + 
							p[i] * p[k + 1] * p[j + 1];

				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}

	cout << dp[0][N - 1] << '\n';
	return 0;
}