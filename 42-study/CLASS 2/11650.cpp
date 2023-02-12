/**
 * @file 11650.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 좌표 정렬하기
 * @date 2023-02-11
 *
 * x좌표가 증가하는 순으로, 같으면 y좌표가 증가하는 순서로 정렬
 *
 * 점의 개수 N (1 <= N <= 100,000)
 * -100,000 <= xi, yi <= 100,000
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::vector<std::pair<int, int> > points;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::pair<int, int> point;

		std::cin >> point.first >> point.second;
		points.push_back(point);
	}

	std::sort(points.begin(), points.end(),
			  [](std::pair<int, int> front, std::pair<int, int> back) -> bool {
				  if (front.first == back.first) {
					  return front.second < back.second;
				  }
				  return front.first < back.first;
			  });

	for (auto point : points) {
		std::cout << point.first << ' ' << point.second << '\n';
	}
}
