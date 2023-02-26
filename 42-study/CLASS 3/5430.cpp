/**
 * @file 5430.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief AC
 * @date 2023-02-26
 *
 * AC는 정수 배열에 연산을 하기 위해 만든 언어이다.
 * 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
 *
 * R : 배열에 있는 수의 순서를 뒤집는 함수
 * D : 첫 번째 수를 버리는 함수 (비어있으면 Error)
 *
 * 함수는 조합해서 사용할 수 있다.
 * 배열의 초기값과 수행할 함수가 주어지면, 최종 결과를 구해라
 *
 * 테스트 케이스 개수 T 최대 100
 * 수행할 함수 p (1 <= p <= 100,000)
 * 배열에 들어있는 수 개수 n (0 <= n <= 100,000)
 * 정수 (1 <= x <= 100)
 *
 * 자료구조
 * - 배열은 첫 번째 수를 삭제하는데 오버헤드가 많이 든다.
 * - Deque가 적절할 것 같다.
 *
 * 1. RR과 같은 중복된 연산을 제거한다.
 * 2. D는 첫 번째 수를 버린다. (pop)
 * 3. R은 현재 위치를 반대로 바꾼다. (iterator)
 *
 * 출력 형식에서 개행이 빠져서 10번은 트라이한 문제...
 * 자료구조를 이용한 구현문제
 */
#include <cctype>
#include <deque>
#include <iostream>

void solve() {
	std::deque<int> deq;

	std::string cmd;
	int count;
	std::string numbers;

	std::cin >> cmd >> count >> numbers;

	std::string temp = "";

	for (int i = 0; i < numbers.size(); i++) {
		if (isdigit(numbers[i])) {
			temp += numbers[i];
		} else {
			if (temp.size()) {
				deq.push_back(std::stoi(temp));
				temp.clear();
			}
		}
	}

	bool reverse = false;
	for (int i = 0; i < cmd.length(); i++) {
		if (cmd[i] == 'D') {
			if (deq.empty()) {
				std::cout << "error" << '\n';
				return;
			}
			if (reverse) {
				deq.pop_back();
			} else {
				deq.pop_front();
			}
		} else if (cmd[i] == 'R') {
			reverse = !reverse;
		}
	}

	std::cout << '[';
	while (!deq.empty()) {
		if (reverse) {
			std::cout << deq.back();
			deq.pop_back();
		} else {
			std::cout << deq.front();
			deq.pop_front();
		}
		if (!deq.empty()) {
			std::cout << ',';
		}
	}
	std::cout << ']' << '\n';
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
