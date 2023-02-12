/**
 * @file 11651.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 좌표 정렬하기 2
 * @date 2023-02-11
 *
 * y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순으로 정렬
 */
#include <algorithm>
#include <iostream>
#include <vector>

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
			  [](std::pair<int, int> x, std::pair<int, int> y) -> bool {
				  if (x.second == y.second) {
					  return x.first < y.first;
				  }
				  return x.second < y.second;
			  });

	for (auto point : points) {
		std::cout << point.first << ' ' << point.second << '\n';
	}
}
