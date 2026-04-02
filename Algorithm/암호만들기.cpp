#include <bits/stdc++.h>

using namespace std;
// mask, prev_permutation 안쓰고 재귀방식으로 풀었음 (너무 재귀 안쓴지 오래되서)

int L, C;
bool IsValid(vector<char>& password)
{
	int vowel = 0, consonant = 0;
	for (char c : password) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel++;
		else consonant++;
	}
	return vowel >= 1 && consonant >= 2;
}
void PrintPassword(const vector<char>& origin, vector<char>& password, int level, int idx)
{
	if (level == L)
	{
		if (IsValid(password)) {
			for (char c : password) cout << c;
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i < C; ++i)
	{
		password[level] = origin[i];
		PrintPassword(origin, password, level + 1, i + 1);
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;

	vector<char> arr(C, 0);
	for (int i = 0; i < C; ++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	vector<char> b(L, 0);
	PrintPassword(arr, b, 0, 0);

	return 0;
}