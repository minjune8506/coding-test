/**
 * @file 9019.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief DSLR
 * @date 2023-03-04
 *
 * 레지스터에는 0 이상 10,000 미만의 십진수를 저장할 수 있다.
 * 각 명령어는 n을 다음과 같이 변환한다.
 * n = d1d2d3d4
 * n = ((d1 * 10 + d2) * 10 + d3) * 10 + d4
 *
 * D : n을 두배로 바꾼다. 결과 값이 9999보다 크면 10000으로 나눈
 * 나머지를 취한다. 결과값 (2n mod 10000)를 저장
 *
 * S : n - 1을 레지스터에 저장 n이 0이면 9999 저장
 *
 * L : n의 각 자릿수를 왼편으로 회전시켜 저장
 *
 * R : n의 각 자릿수를 오른편으로 회전시켜 저장
 *
 * 숫자 A를 B로 DSLR 명령어를 사용해 변환하려고 한다.
 * 필요한 최소한의 명령어 나열을 출력
 *
 * - 전혀 하나도 감이 안잡힘
 * - BFS 문제 !
 */
#include <cstring>
#include <iostream>
#include <queue>

bool visited[10000];

void solve(int A, int B) {
	std::queue<std::pair<int, std::string> > q;

	q.push(std::make_pair(A, ""));
	visited[A] = true;

	while (true) {
		std::pair<int, std::string> front = q.front();
		q.pop();

		if (front.first == B) {
			std::cout << front.second << '\n';
			break;
		}

		int nx;

		nx = front.first * 2 % 10000;
		if (!visited[nx]) {
			q.push(std::make_pair(nx, front.second + "D"));
			visited[nx] = true;
		}

		nx = front.first - 1;
		if (nx < 0) {
			nx = 9999;
		}
		if (!visited[nx]) {
			q.push(std::make_pair(nx, front.second + "S"));
			visited[nx] = true;
		}

		nx = (front.first % 1000) * 10 + (front.first / 1000);
		if (!visited[nx]) {
			q.push(std::make_pair(nx, front.second + "L"));
			visited[nx] = true;
		}

		nx = (front.first % 10) * 1000 + (front.first / 10);
		if (!visited[nx]) {
			q.push(std::make_pair(nx, front.second + "R"));
			visited[nx] = true;
		}
	}
}

int main(void) {
	int t;
	std::cin >> t;

	while (t > 0) {
		int A, B;

		std::cin >> A >> B;
		solve(A, B);
		memset(visited, false, 10000);
		t--;
	}
}
