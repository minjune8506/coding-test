/**
 * @file 1931.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 회의실 배정
 * @date 2023-02-22
 *
 * 한 개의 회의실을 N개의 회의에 대해 사용표를 만드려고 한다.
 * 각 회의 I에 대해 시작시간과 끝나는 시간이 주어지고
 * 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를
 * 찾아보자.
 * 한 회의가 끝남과 동시에 다음 회의가 시작될 수 있다.
 * 시작시간과 끝나는 시간이 같을 수도 있다.
 *
 * N (1 <= N <= 100,000)
 * 시작시간 st, 끝나는시간 et <= 2^31 - 1
 *
 * 회의 시간이 짧은 것들 위주로 회의를 배정해야한다.
 *
 * 해답
 * - 회의가 일찍 끝나는 순으로 정렬한다.
 * - 끝나는 시간이 같으면 더 늦게 시작하는 순으로 정렬한다.
 */
#include <algorithm>
#include <iostream>
#include <vector>

typedef struct s_meeting {
	int start;
	int end;
	int duration;
} t_meeting;

int main(void) {
	int N;

	std::cin >> N;
	std::vector<t_meeting> meetings;

	for (int i = 0; i < N; i++) {
		t_meeting meeting;
		std::cin >> meeting.start >> meeting.end;
		meeting.duration = meeting.end - meeting.start;
		meetings.push_back(meeting);
	}
	std::sort(meetings.begin(), meetings.end(),
			  [](t_meeting x, t_meeting y) -> bool {
				  if (x.end == y.end) {
					  return x.start < y.start;
				  }
				  return x.end < y.end;
			  });
	int count = 1;
	int current = 0;
	for (int i = 1; i < meetings.size(); i++) {
		if (meetings[current].end > meetings[i].start) {
			continue;
		}
		current = i;
		count++;
	}
	std::cout << count << std::endl;
}
