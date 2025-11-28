
#pragma region DP
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[2002];
int dp[2002][2002]; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	// ÆÓ¸°µå·Ò dp
	for (int i = 1; i <= N; ++i)
	{
		dp[i][i] = 1;
		if (i < N && arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = N - 2; i >= 1; --i)
	{
		for (int j = i + 2; j <= N; ++j)
		{
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1)
				dp[i][j] = 1;
		}
	}

	// Äõ¸® Ã³¸®
	cin >> M;
	int s{}, e{};
	for (int i = 0; i < M; ++i)
	{
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
	return 0;
}
#pragma endregion



#pragma region ÅõÆ÷ÀÎÅÍ -> ½Ã°£ÃÊ°ú
//#include <bits/stdc++.h>
//using namespace std;
//
//int N, M;
//void Solution(vector<int>& arr, int s, int e)
//{
//	int answer = 1;
//	int len = e - s + 1;
//	
//	int l{}, r{};
//	if (len % 2)	// È¦¼ö
//	{
//		l = r = (e + s) / 2;
//	}
//	else			// Â¦¼ö
//	{
//		l = (e + s) / 2;
//		r = l + 1;
//	}
//
//	while (l >= s && r <= e)
//	{
//		if (arr[l] != arr[r])
//		{
//			answer = 0;
//			break;
//		}
//
//		--l; ++r;
//	}
//
//	cout << answer << '\n';
//}
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N;
//
//	vector<int> arr(N + 1);
//	for (int i = 1; i <= N; ++i)
//		cin >> arr[i];
//
//	cin >> M;
//	for (int i = 0; i < M; ++i)
//	{
//		int s, e;
//		cin >> s >> e;
//		Solution(arr, s, e);
//	}
//
//	return 0;
//}
#pragma endregion

