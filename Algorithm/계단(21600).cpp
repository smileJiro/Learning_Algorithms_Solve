#include <bits/stdc++.h>

using namespace std;


int L;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L;

	int cur = 0;
	int answer = 0;
	for (int i = 0; i < L; ++i)
	{
		int input;
		cin >> input;

		if (input > cur)
			++cur;
		else
			cur = input;

		answer = max(answer, cur);
	}

	cout << answer << '\n';

	return 0;
}