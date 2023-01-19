/**
 * @file 2577.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 숫자의 개수
 * @date 2023-01-20
 * 
 * A, B, C 세 자연수가 주어질때
 * A x B x C 를 계산한 결과에 0부터 9까지의 각 숫자가 몇 번씩 쓰였는지 구하는 프로그램
 * 
 * A, B, C는 1000보다 작은 자연수이다. 즉 최대 1,000,000,000
 * 
 * - A, B, C를 입력받는다.
 * - A, B, C의 곱을 저장한다.
 * - 0 ~ 9를 저장할 배열에 각 자리 수가 몇번 나왔는지 저장한다.
 * - 출력
 */
#include <iostream>

int main(void) {
	int A, B, C;

	std::cin >> A >> B >> C;
	int multiple = A * B * C;
	int counts[10] = {};

	while (multiple != 0) {
		counts[multiple % 10]++;
		multiple /= 10;
	}

	for (int i = 0; i < 10; i++) {
		std::cout << counts[i] << std::endl;
	}
}
