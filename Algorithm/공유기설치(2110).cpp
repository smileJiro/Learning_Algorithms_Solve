#include <bits/stdc++.h>
using namespace std;


int N, C;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;

    vector<int> positions(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> positions[i];
    }
    sort(positions.begin(), positions.end());
    
    // 이분 탐색 m => answer => 두 공유기 사이의 거리의 최소? 

    using ll = long long;
    ll answer = 0;
    ll s{0},m{0},e{positions.back() - positions.front()};
    while (s <= e)
    {
        m = (s + e) >> 1;

        // m 간격으로 공유기를 설치해볼거임 C개 설치가 가능 or 불가능
        int c = 1; // 시작 집엔 그냥 무조건 까는 것임 
        int prev = 0, cur = 1;
        for(int cur = 1; cur < N; ++cur)
        {
            if(m <= positions[cur] - positions[prev])
            {
                c += 1; // 공유기 설치
                prev = cur;
            }
        }

        if(c >= C) // 조건 만족 -> 거리를 늘려보자 
        {
            s = m + 1;
            answer = m;
        }
        else    // 불만족 -> 거리 줄인다
        {
            e = m - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}


// 틀린 답 -> 완탐
// // 5P3를 돌리면서, 순열을 만들고, 거리를 잰다?
//     vector<int> mask(N, 0);
//     fill(mask.begin(), mask.begin() + C, 1);
    
//     int answer = 0;
//     do
//     {
//         // 1. 마스크 순회하면서 가장 인접한 공유기 사이의 거리 찾기
//         vector<int> routers;
//         for(int i = 0; i < N; ++i)
//         {
//             if(mask[i])
//             {
//                 routers.push_back(positions[i]);
//             }
//         }
//         // 2. 가장 인접한 공유기 찾기
//         int minDist = 1e9;
//         for(int i = 1; i < C; ++i)
//         {
//             minDist = min(minDist, routers[i] - routers[i - 1]);
//         }

//         // 3. max 갱신
//         answer = max(answer, minDist);
//     } while (prev_permutation(mask.begin(), mask.end()));