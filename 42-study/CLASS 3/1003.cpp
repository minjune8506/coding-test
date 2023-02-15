/**
 * @file 1003.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 피보나치 함수
 * @date 2023-02-14
 *
 * fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구해라
 * 시간 초과 -> DP이용
 * 0과 1이 나오는 횟수를 저장하여 보관한다.
 */
#include <iostream>

int zeroCount[41], oneCount[41];

void fibonacci(int n) {
	zeroCount[0] = 1;
	zeroCount[1] = 0;
	oneCount[0] = 0;
	oneCount[1] = 1;
	for (int i = 2; i <= n; i++) {
		zeroCount[i] = zeroCount[i - 1] + zeroCount[i - 2];
		oneCount[i] = oneCount[i - 1] + oneCount[i - 2];
	}
}

int main(void) {
	int tc;

	std::cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n;
		std::cin >> n;
		if (!zeroCount[n] || !oneCount[n]) {
			fibonacci(n);
		}
		std::cout << zeroCount[n] << ' ' << oneCount[n] << '\n';
	}
}
