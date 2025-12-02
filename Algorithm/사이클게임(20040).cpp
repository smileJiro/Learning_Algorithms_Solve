#include <bits/stdc++.h>
using namespace std;

int N, M;
// 유니온 파인드 구현
int rootTable[500002];
int FindRoot(int node)
{
	if (rootTable[node] == node)
		return node;

	return rootTable[node] = FindRoot(rootTable[node]);
}
bool AddEdge(int node1, int node2)
{
	int root1 = FindRoot(node1);
	int root2 = FindRoot(node2);
	if (root1 == root2)
		return false;

	if (root1 < root2)
		rootTable[root2] = root1;
	else
		rootTable[root1] = root2;

	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i <= N; ++i)
		rootTable[i] = i;

	for (int i = 0; i < M; ++i)
	{
		int node1, node2;
		cin >> node1 >> node2;
		if (!AddEdge(node1, node2))
		{
			cout << i + 1 << '\n';
			return 0;
		}
	}

	cout << 0 << '\n';
	return 0;
}