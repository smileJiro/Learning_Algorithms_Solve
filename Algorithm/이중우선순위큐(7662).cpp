#include <bits/stdc++.h>
using namespace std;

// pq 두개쓰고 데이터 수만 별도로 마킹한다?

int T;
int K;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> K;
		unordered_map<int, int> hash;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		priority_queue<int> maxHeap;
		for (int i = 0; i < K; ++i)
		{
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I')
			{
				minHeap.push(n);
				maxHeap.push(n);
				hash[n] += 1;
			}
			else
			{
				if (n == 1)
				{
					while (!maxHeap.empty() && !hash[maxHeap.top()])
						maxHeap.pop();

					if (maxHeap.empty())
						continue;
					hash[maxHeap.top()] -= 1;
					if(!hash[maxHeap.top()])
						maxHeap.pop();
				}
				else
				{
					while (!minHeap.empty() && !hash[minHeap.top()])
						minHeap.pop();

					if (minHeap.empty())
						continue;

					hash[minHeap.top()] -= 1;
					if (!hash[minHeap.top()])
						minHeap.pop();
				}
			}
		}

		bool isEmpty = true;
		int maxValue = 0;
		int minValue = 0;
		while (!maxHeap.empty())
		{
			if (hash[maxHeap.top()])
			{
				isEmpty = false;
				maxValue = maxHeap.top();
				break;
			}
			maxHeap.pop();
		}

		while (!minHeap.empty())
		{
			if (hash[minHeap.top()])
			{
				isEmpty = false;
				minValue = minHeap.top();
				break;
			}
			minHeap.pop();
		}

		if (isEmpty)
			cout << "EMPTY" << '\n';
		else
		{
			cout << maxValue << ' ' << minValue << '\n';
		}

	}

	return 0;
}