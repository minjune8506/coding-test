/**
 * @file 8958.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief OX퀴즈
 * @date 2023-02-25
 *
 * O : 문제 맞음
 * X : 문제 틀림
 *
 * 문제까지 연속된 O의 개수 : 점수
 * OOXXOXXOOO
 * 1 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3
 *
 */
#include <iostream>

void solve() {
	std::string answers;

	std::cin >> answers;
	int sum = 0;
	int ary[answers.size()];
	for (int i = 0; i < answers.size(); i++) {
		if (answers.at(i) == 'O') {
			if (i > 0) {
				ary[i] = ary[i - 1] + 1;
			} else {
				ary[i] = 1;
			}
			sum += ary[i];
		} else {
			ary[i] = 0;
		}
	}
	std::cout << sum << '\n';
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int testCase;

	std::cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		solve();
	}
}
