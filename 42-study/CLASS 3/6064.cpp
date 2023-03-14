/**
 * @file 6064.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 카잉 달력
 * @date 2023-03-14
 */

#include <iostream>

int gcd(int a, int b) {	 // 최대 공약수
	if (b == 0) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {	 // 최소 공배수
	return (a * b) / gcd(a, b);
}

int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++) {
		int m, n, x, y;
		int result = -1;
		std::cin >> m >> n >> x >> y;
		int maxi = lcm(m, n);
		for (int i = x; i <= maxi; i += m) {
			int ny = i % n;	 // y값
			if (ny == 0) {	 // 이때는 y가 최대값이 됨
				ny = n;
			}
			if (ny == y) {	// 정답
				result = i;
				break;
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}
