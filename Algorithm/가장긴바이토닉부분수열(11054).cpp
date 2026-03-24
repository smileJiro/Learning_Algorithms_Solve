#include <bits/stdc++.h>

using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	int answer = 0;
	for (int cur = 0; cur < N; ++cur)
	{
		// arr[cur] 가 Sk일때, 가장 긴 바이토닉을 구한다.
		// 0 ~ cur까지 LIS -> A그룹 , cur ~ N - 1까지 LDS -> B그룹
		// A + B - 1;

		// LIS
		vector<int> A;
		A.push_back(arr[0]);
		for (int i = 1; i <= cur; ++i)
		{
			if (A.back() < arr[i])
				A.push_back(arr[i]);
			else
			{
				auto iter = lower_bound(A.begin(), A.end(), arr[i]);
				*iter = arr[i];
			}
		}
		int countA = A.size();

		// LDS
		vector<int> B;
		vector<int> rev = arr;
		reverse(rev.begin(), rev.end());
		int revcur = N - 1 - cur; // 인덱스 반전
		B.push_back(rev[0]);
		for (int i = 1; i <= revcur; ++i)
		{
			if (B.back() < rev[i])
				B.push_back(rev[i]);
			else
			{
				auto iter = lower_bound(B.begin(), B.end(), rev[i]);
				*iter = rev[i];
			}
		}
		int countB = B.size();

		answer = max(answer, countA + countB - 1);
	}
	cout << answer << '\n';
	return 0;
}