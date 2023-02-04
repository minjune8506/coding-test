/**
 * @file 2805.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 나무 자르기
 * @date 2023-02-04
 * ! 다시 풀어보기
 * 
 * 나무 M미터가 필요하다.
 * 높이 H를 지정하면 연속해 있는 나무를 모두 절단한다.
 * 높이가 H보다 큰 나무는 H의 윗부분이 잘릴 것이고,
 * 낮은 나무는 잘리지 않을 것이다.
 *
 * e.g. 20, 15, 10, 17 / 높이 15 지정
 * 15, 15, 10, 15 // (5, 0, 0, 2) -> 7 meter
 *
 * 설정할 수 있는 높이는 양의 정수 또는 0이다.
 * 적어도 나무 M미터를 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값
 *
 * 나무의 수 : N (1 <= N <= 1,000,000)
 * 나무의 길이 : M (1 <= M <= 2,000,000,000)
 *
 * 풀이 방법
 * - 나무의 높이를 정하고 잘랐을 때 얼마나 가져갈 수 있는지 구한다.
 * - 나무의 높이는 1부터 시작해서 나무들의 최대 높이만큼 반복한다.
 * - 자른 나무의 높이가 M미터보다 크거나 같을때 절단기 높이를 저장한다.
 * - 절단기 높이의 모음을 정렬한다.
 * - 가장 높은 절단기 높이의 값을 출력한다.
 *
 * 예제는 통과했지만 시간 초과가 날 것 같은 느낌.. (시간초과)
 *
 * 이분탐색을 이용해야 할 것 같다.
 * 절단기의 높이를 최대 나무 높이의 중간부터 시작한다.
 * - 자른 나무의 높이가 M보다 크면? -> 절단기의 높이를 올린다.
 * - 자른 나무의 높이가 M보다 작다면 ? -> 절단기의 높이를 낮춘다.
 *
 * 높이를 낮추고 올릴때 반만큼 증가 감소한다.
 * lowwer bound / upper bound를 이용한다.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
	int treeCount;
	int target;
	std::vector<int> trees;

	std::cin >> treeCount >> target;
	int treeMaxHeight = -1;
	for (int i = 0; i < treeCount; i++) {
		int tree;
		std::cin >> tree;
		if (tree > treeMaxHeight) {
			treeMaxHeight = tree;
		}
		trees.push_back(tree);
	}

	std::vector<int> cutterHeights;

	int start = 0, end = treeMaxHeight;
	int cutterHeight;
	int result;
	while (end > start) {
		long long loggedTreeSum = 0;
		cutterHeight = (start + end) / 2;
		for (int i = 0; i < trees.size(); i++) {
			int loggedTreeHeight = trees[i] - cutterHeight;
			loggedTreeHeight = loggedTreeHeight < 0 ? 0 : loggedTreeHeight;
			loggedTreeSum += loggedTreeHeight;
		}
		if (loggedTreeSum >= target) {
			start = cutterHeight + 1;
			result = cutterHeight;
		} else {
			end = cutterHeight;
		}
	}
	std::cout << result << std::endl;
}
