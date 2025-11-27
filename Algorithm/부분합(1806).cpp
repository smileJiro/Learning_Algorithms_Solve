#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e9;

int N, S;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;

	vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];



	int l{ 0 }, r{ 0 };
	int answer = INF;
	int sum = arr[l];
	while (l <= r)		// 길이가 1인 부분합 갱신 -> 조기 종료
	{
		if (S <= sum)
		{
			answer = min(answer, r - l + 1);
			sum -= arr[l++];
		}
		else
		{
			if (r + 1 >= N)
				break;
			sum += arr[++r];
		}
	}

	if (answer == INF)
		cout << 0 << '\n';
	else
		cout << answer << '\n';
	return 0;
}