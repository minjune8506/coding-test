/**
 * @file 5525.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief IOIOI
 * @date 2023-03-19
 *
 * N + 1개의 I와 N개의 O로 이루어져 있다.
 * P1 : IOI (I: 2 / O: 1)
 * P2 : IOIOI (I: 3 / O: 2)
 * P3 : IOIOIOI (I: 4 / O: 3)
 *
 * I와 O로만 이루어진 문자열 S와 정수 N이 주어지면
 * S안에 PN이 몇군데 포함되어 있는지 구해라
 *
 * I아니면 O로만 이루어진 문자열
 * O : 앞뒤로 I가 있어야 함
 */
#include <iostream>

int main(void) {
	int N, M;
	std::string S;

	std::cin >> N >> M;
	std::cin >> S;

	int oCount = 0;
	int answer = 0;
	for (int i = 1; i < M - 1; i++) {
		while (i < M - 1 && S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
			oCount++;
			if (oCount == N) {
				oCount--;
				answer++;
			}
			i += 2;
		}
		oCount = 0;
	}
	std::cout << answer << '\n';
}
