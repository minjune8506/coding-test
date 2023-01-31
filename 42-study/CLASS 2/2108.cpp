/**
 * @file 2108.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 통계학
 * @date 2023-01-31
 *
 * N개의 수를 대표하는 기본 통계 값에는 다음과 같은 값이 있다.
 * N은 홀수라고 가정한다.
 *
 * 1. 산술평균 : N개의 수들의 합을 N으로 나눈 값 (소수점 첫째 자리에서 반올림)
 * 2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
 * 3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값 (여러개인 경우 두번째로 작은 값)
 * 4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

double calculateAverage(std::vector<int> &numbers) {
	double sum = 0;
	for (auto number : numbers) {
		sum += number;
	}
	return sum / numbers.size();
}

int getMedianValue(std::vector<int> &sorted) {
	return sorted[sorted.size() / 2];
}

int getMode(std::vector<int> &sorted) {
	std::unordered_map<int, int> numberCounts;

	for (auto number : sorted) {
		auto it = numberCounts.find(number);
		if (it == numberCounts.end()) {
			numberCounts.insert(std::make_pair(number, 1));
		} else {
			it->second++;
		}
	}

	int maxCount = -1;
	for (auto numberCount : numberCounts) {
		if (maxCount < numberCount.second) {
			maxCount = numberCount.second;
		}
	}

	std::vector<std::pair<int, int> > modes;
	for (auto numberCount : numberCounts) {
		if (maxCount == numberCount.second) {
			modes.push_back(numberCount);
		}
	}

	std::sort(modes.begin(), modes.end(),
			  [](std::pair<int, int> x, std::pair<int, int> y) -> bool {
				return x.first < y.first;
			  });
	if (modes.size() > 1) {
		return modes[1].first;
	}
	return modes[0].first;
}

int getNumberRange(std::vector<int> &sorted) {
	return sorted[sorted.size() - 1] - sorted[0];
}

int main(void) {
	int N;
	std::vector<int> numbers;
	std::vector<int> sorted;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int number;

		std::cin >> number;
		numbers.push_back(number);
	}

	sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	int average = round(calculateAverage(numbers));
	std::cout << (average == 0 ? 0 : average) << '\n'
			  << getMedianValue(sorted) << '\n'
			  << getMode(sorted) << '\n'
			  << getNumberRange(sorted) << std::endl;
}
