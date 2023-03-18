/**
 * @file 1931.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 회의실 배정
 * @date 2023-03-18
 *
 * 끝나는 시간을 기준으로 정렬
 * 끝나는 시간이 같으면 일찍 시작하는 순으로 정렬
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int> > meetings;

	for (int i = 0; i < N; i++) {
		int start, end;
		std::cin >> start >> end;
		meetings.push_back(std::make_pair(start, end));
	}

	std::sort(meetings.begin(), meetings.end(),
			  [](std::pair<int, int> x, std::pair<int, int> y) -> bool {
				  if (x.second == y.second) {
					  return x.first < y.first;
				  }
				  return x.second < y.second;
			  });

	int count = 0;
	int endTime = -1;
	for (int i = 0; i < meetings.size(); i++) {
		if (meetings[i].first >= endTime) {
			count++;
			endTime = meetings[i].second;
		}
	}
	std::cout << count << '\n';
}
