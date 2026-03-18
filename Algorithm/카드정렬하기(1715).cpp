#include <bits/stdc++.h>
using namespace std;


int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> deckList;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		deckList.push(num);
	}
	
	int sum = 0;
	while (deckList.size() > 1)
	{
		int v1 = deckList.top(); deckList.pop();
		int v2 = deckList.top(); deckList.pop();
		sum += v1 + v2;
		deckList.push(v1 + v2);
	}

	cout << sum << '\n';
	return 0;
}