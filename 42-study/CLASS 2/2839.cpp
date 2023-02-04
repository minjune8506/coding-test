/**
 * @file 2839.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 설탕 배달
 * @date 2023-02-04
 *
 * 설탕을 정확하게 N킬로그램 배달해야 한다.
 * 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.
 * 최대한 적은 봉지를 들고 가려고 한다.
 * N킬로그램 배달해야 할때, 봉지 몇개를 가져가야 하는지 그 수를 구해라
 *
 * 정확하게 N킬로그램을 만들 수 없다면 -1을 출력한다.
 * 3 <= N <= 5000
 *
 * 풀이
 * - Greedy 알고리즘으로 해결할 수 있는가?
 * 18 : 5 * 3 + 3 * 1 -> 4개
 * 4 : 5 * 0 + 3 * 1 (1) -> -1
 * 6 : 5 * 1 + 3 * ? -> Greedy 불가능
 *
 * - 대안 : 완전탐색 (해결)
 */
#include <climits>
#include <iostream>

int main(void) {
	int N;
	int min = INT_MAX;

	std::cin >> N;

	for (int i = 0; i * 5 <= N; i++) {
		for (int j = 0; i * 5 + j * 3 <= N; j++) {
			if (i * 5 + j * 3 == N) {
				min = min > (i + j) ? (i + j) : min;
			}
		}
	}
	std::cout << (min == INT_MAX ? -1 : min) << std::endl;
}
