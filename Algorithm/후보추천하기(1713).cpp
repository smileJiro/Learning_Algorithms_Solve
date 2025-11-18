#include <bits/stdc++.h>
using namespace std;
int N, M;

struct Frame
{
public:
	Frame(int i, int c, int t)
		:idx(i), count(c), time(t)
	{	}
	int idx;
	int count;
	int time;
};

int g_time = 0; 

auto worse = [](const Frame& a, const Frame& b) {
	if (a.count != b.count)
		return a.count < b.count;   // 추천 수 적을수록 나쁨
	return a.time < b.time;         // 더 오래된 애가 나쁨
	};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	vector<Frame> frames;
	frames.reserve(N);
	

	for (int i = 0; i < M; ++i)
	{
		int n;
		cin >> n;

		// 1. 중복 검사
		bool isIn = false;
		for (auto& x : frames) 
		{
			if (x.idx == n)
			{
				x.count += 1;
				isIn = true;
				break;
			}
		}
		if (isIn) continue;

		// 2. 중복이 아닌 경우
		if (frames.size() < N)
		{
			// 비어있다면,
			frames.emplace_back(n, 1, g_time++);
		}
		else
		{
			// 비어 있지 않다면, 퇴출자를 탐색
			sort(frames.begin(), frames.end(), worse);

			Frame& out = frames.front();
			out.count = 1;
			out.idx = n;
			out.time = g_time++;
		}
	}

	vector<int> answer(frames.size());
	for (int i = 0; i < frames.size(); ++i)
	{
		answer[i] = frames[i].idx;
	}

	sort(answer.begin(), answer.end());
	for (int i : answer)
		cout << i << ' ';


	return 0;
}

// 2 1 4
// 3 1 4 
// 3 5 4 
// 3 5 6
// 2 5 6
// 2 7 6


// 틀린 이유 
// 전체 추천 수 카운팅은 별도로 한다. X -> 이거때문에 틀렸었어 프레임 위에 올라간 후 추천수만 세는거야
// 사진 틀이 핵심이다.
// 그냥 간단하게 시키는대로 구현하는 문제를 자꾸 더 나은 해법이 없나 고민하다가 풀이 시간이 늘어졌음
// 시간복잡도 널널하면 그냥 바로 구현하는 연습을 더 해야함

// 풀이
// 1. 중복 추천자인지 검사한다. -> 중복 추천자면 추천 횟수만 증가하고 continue;
// 2. 중복 추천자가 아니라면, -> frame에 무조건 넣는다
// 3. 만약 frame이 가득 찬 상황이다 -> frame에서 제거할 후보를 찾고 그 자리에 새 후보를 넣는다.
// 주의! : 새로 frame에 들어가는 후보의 추천 횟수는 무조건 1이야!
