/**
 * @file 1676.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 팩토리얼 0의 개수
 * @date 2023-02-19
 *
 * N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지
 * 0의 개수를 구하는 프로그램을 작성해라
 *
 * 0 <= N <= 500
 *
 * 2 * 5 => 10
 * 2와 5가 몇개있는지 검사하면 된다. -> 해결
 */
#include <iostream>

int countTwo, countFive;

void count(int number) {
	int count = 0;
	while (!(number % 2) || !(number % 5)) {
		if (!(number % 2)) {
			number /= 2;
			countTwo++;
		} else if (!(number % 5)) {
			number /= 5;
			countFive++;
		}
	}
}

int main(void) {
	int N;

	std::cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		count(i);
	}
	std::cout << (countTwo > countFive ? countFive : countTwo) << std::endl;
}
