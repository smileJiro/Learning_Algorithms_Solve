#include <bits/stdc++.h>

using namespace std;

int N, K;
int visited[100001];
using P = pair<int, int>;
int main()
{
	cin >> N >> K;

	if (N >= K)
	{
		cout << N - K << '\n';
		return 0;
	}

	priority_queue<P, vector<P>, greater<P>> q; // level, value
	q.emplace(0, N);
	while (!q.empty())
	{
		auto [curlevel, curvalue] = q.top(); q.pop();
		if (curvalue == K)
		{
			cout << curlevel << '\n';
			return 0;
		}

		int newlevel = curlevel + 1;
		for (int i = 0; i < 3; ++i)
		{
			int newValue = curvalue;
			if (i == 1)
			{
				newValue += 1;
				newlevel = curlevel + 1;
			}
			else if (i == 2)
			{
				newValue -= 1;
				newlevel = curlevel + 1;
			}
			else
			{
				newValue *= 2;
				newlevel = curlevel;
			}

			if (0 <= newValue && 100001 > newValue && visited[newValue] == 0)
			{
				visited[newValue] = 1;
				q.emplace(newlevel, newValue);
			}
		}
	}
	return 0;
}