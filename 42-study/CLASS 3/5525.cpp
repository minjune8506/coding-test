/**
 * @file 5525.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief IOIOI
 * @date 2023-02-27
 *
 * N + 1개의 I와 N개의 O로 이루어져 있고, I와 O가 교대로 나오는 문자열을
 * PN이라고 한다.
 *
 * P1 IOI
 * P2 IOIOI
 * P3 IOIOIOI
 *
 * I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때
 * S안에 PN이 몇 군데 포함되어 있는지 구해라
 *
 * 1 <= N <= 1,000,000
 * 2N + 1 <= M(S의 길이) <= 1,000,000
 * S는 I와 O로만 이루어져 있다.
 *
 * 50점 -> 시간초과 (substring 이용하지 않고 해결)
 */
#include <iostream>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::string S;

	std::cin >> N >> M >> S;

	int answer = 0;
	for (int i = 0; i < M; i++) {
		if (S[i] == 'I') {
			int oCount = 0;
			while (i + 2 < M && S[i + 1] == 'O' && S[i + 2] == 'I') {
				oCount++;
				i += 2;
				if (oCount == N) {
					oCount--;
					answer++;
				}
			}
		}
	}
	std::cout << answer << '\n';
}
