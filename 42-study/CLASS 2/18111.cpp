/**
 * @file 18111.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 마인크래프트
 * @date 2023-02-13
 *
 * 세로 M, 가로 N 크기의 집터를 고른다.
 * 맨 왼쪽 위의 좌표는 (0, 0)
 * 집터 내의 땅의 높이를 일정하게 바꾸는 것이 목적이다.
 * 1. 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
 * 2. 인벤토리에서 블록 하나를 꺼내 좌표 (i, j)의 가장 위에 있는 블록 위에
 * 놓는다.
 * 1번은 2초, 2번은 1초 소요
 * 땅 고르기 작업에 걸리는 최소 시간과 땅의 높이를 출력해라.
 * 작업을 시작할때 인벤토리에는 B개의 블록이 들어있다.
 * 땅의 높이는 256블록을 초과할 수 없고, 음수가 될 수 없다.
 * 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력해라.
 *
 * 1 <= M, N <= 500, 0 <= B <= 6.3 x 10^7
 *
 * - 높이의 최솟값, 최댓값을 저장한다.
 * - 최솟값부터 최댓값까지 반복하며 땅의 높이를 평평하게 만드는데
 * 얼마나 많은 시간이 걸리는지 계산한다.
 */
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int M, N, B;

	std::cin >> M >> N >> B;
	std::vector<int> land;
	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int height;
			std::cin >> height;
			if (max < height) {
				max = height;
			}
			if (min > height) {
				min = height;
			}
			land.push_back(height);
		}
	}

	std::vector<std::pair<int, int> > answers;

	int removed = 0;
	int placed = 0;
	int blockCount = 0;
	for (int height = min; height <= max;
		 height++, blockCount = 0, removed = 0, placed = 0) {
		for (auto block : land) {
			if (block != height) {
				if (block < height) {
					placed += (height - block);
					blockCount += (height - block);
				} else if (block > height) {
					removed += (block - height);
					blockCount -= (block - height);
				}
			}
		}
		if (blockCount <= B) {
			int time = placed * 1 + removed * 2;
			answers.push_back(std::make_pair(time, height));
		}
	}

	std::sort(answers.begin(), answers.end(),
			  [](std::pair<int, int> x, std::pair<int, int> y) -> bool {
				  if (x.first == y.first) {
					  return x.second > y.second;
				  }
				  return x.first < y.first;
			  });
	if (answers.size()) {
		std::cout << answers[0].first << ' ' << answers[0].second << std::endl;
	}
}
