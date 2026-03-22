#include <bits/stdc++.h>

using namespace std;

// binary search
// 기준: h
// h보다 높은 부분이 잘림
int N, M; // 나무 수, 목표 목재량
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<int> treeList(N);
    int maxHeight = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> treeList[i];
        maxHeight = max(maxHeight, treeList[i]);
    }

    // binary search

    int s{0}, m{0}, e{maxHeight};
    int answer = 0;
    using ll = long long;
    while (s <= e)
    {
        m = (s + e) >> 1;

        // m: 현재 절단기의 높이
        // 현재 높이 기준으로 가져갈 수 있는 목재량 계산
        ll sum = 0;
        for (int tree : treeList)
        {
            sum += max(0ll, (ll)(tree - m));
        }

        if (sum >= (ll)M)
        {
            s = m + 1;
            answer = m;
        }
        else
        {
            e = m - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}