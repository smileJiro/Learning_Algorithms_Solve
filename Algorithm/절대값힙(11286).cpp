#include <bits/stdc++.h>
using namespace std;
using _uint = unsigned int;
int N;

struct Cmp
{
	bool operator ()(const int a, const int b) const
	{
		int absA{ abs(a) }, absB{ abs(b) };
		if (absA == absB)
			return a > b;

		return absA > absB;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	auto cmp = [](int a, int b) {
		return abs(a) > abs(b);
		};

	priority_queue<int, vector<int>, Cmp> pq;

	vector<int> answer;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		if (x)
			pq.push(x);
		else
		{
			if (pq.empty())
				answer.push_back(0);
			else
			{
				answer.push_back(pq.top());
				pq.pop();
			}
		}

	}

	for (int a : answer)
		cout << a << '\n';

	return 0;
}