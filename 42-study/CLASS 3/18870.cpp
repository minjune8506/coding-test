/**
 * @file 18870.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 좌표 압축
 * @date 2023-02-28
 *
 * 수직선 위에 N개의 좌표가 있다.
 * 이 좌표에 좌표 압축을 적용한다.
 * 결과 X'i의 값은 Xi > Xj를 만족하는 서롤 다른 좌표의 개수와
 * 같아야 한다.
 *
 * 1 <= N <= 1,000,000
 * -10^9 <= Xi <= 10^9
 * 시간제한 2초
 *
 * 좌표를 돌면서 나보다 작은 좌표의 개수를 찾는다. -> O(N^2)
 *
 * 정렬 -> O(NlogN)
 * 중복제거 -> find (시간초과)
 * -> 이분 탐색으로 find 변경 -> 해결
 *
 * 보완
 * - unique, erase 사용
 * - lower bound 사용
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int sequence[N];
	for (int i = 0; i < N; i++) {
		int number;
		std::cin >> number;
		sequence[i] = number;
	}

	std::vector<int> v;
	v.assign(sequence, sequence + N);
	std::sort(v.begin(), v.end());
	// 중복제거
	v.erase(std::unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; i++) {
		auto it = std::lower_bound(v.begin(), v.end(), sequence[i]);
		std::cout << it - v.begin() << ' ';
	}
	std::cout << '\n';
}
