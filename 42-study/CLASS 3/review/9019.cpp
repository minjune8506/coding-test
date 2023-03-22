/**
 * @file 9019.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief DSLR
 * @date 2023-03-22
 *
 * D, S, L, R을 이용하는 계산기
 * 레지스터에는 0이상 10,000 미만의 십진수 저장
 * n의 네자릿수 d1, d2, d3, d4
 * n = (((d1 * 10 + d2) * 10 + d3) * 10 + d4)
 *
 * D : n을 두배로 바꾼다. 9999보다 크면 10000으로 나눈 나머지
 * S : n - 1 ( n == 0 -> 9999)
 * L : 각 자릿수를 왼쪽으로 회전 (d2, d3, d4, d1)
 * R : 각 자릿수를 오른쪽으로 회전 (d4, d1, d2, d3)
 *
 * 정수 A, B가 주어질때 A를 B로 바꾸는 최소한의 명령어 생성
 */
#include <cstring>
#include <iostream>
#include <queue>

void bfs(int A, int B) {
	std::queue<std::pair<int, std::string> > que;

	bool visitied[10000];
	std::memset(visitied, false, 10000);

	visitied[A] = true;
	que.push(std::make_pair(A, ""));

	while (!que.empty()) {
		std::pair<int, std::string> front = que.front();
		que.pop();

		if (front.first == B) {
			std::cout << front.second << '\n';
			break;
		}

		int nx;

		nx = front.first * 2 > 9999 ? front.first * 2 % 10000 : front.first * 2;
		if (!visitied[nx]) {
			visitied[nx] = true;
			que.push(std::make_pair(nx, front.second + "D"));
		}

		nx = front.first - 1 < 0 ? 9999 : front.first - 1;
		if (!visitied[nx]) {
			visitied[nx] = true;
			que.push(std::make_pair(nx, front.second + "S"));
		}

		nx = front.first % 1000 * 10 + front.first / 1000;
		if (!visitied[nx]) {
			visitied[nx] = true;
			que.push(std::make_pair(nx, front.second + "L"));
		}

		nx = front.first % 10 * 1000 + front.first / 10;
		if (!visitied[nx]) {
			visitied[nx] = true;
			que.push(std::make_pair(nx, front.second + "R"));
		}
	}
}

void solve() {
	int A, B;
	std::cin >> A >> B;
	bfs(A, B);
}

int main(void) {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
}
