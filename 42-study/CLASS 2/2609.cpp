/**
 * @file 2609.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 최대공약수와 최소공배수
 * @date 2023-02-01
 * 
 * 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력
 * 자연수는 10,000이하의 자연수이다.
 * 
 * 시간 제한 : 1초
 */
#include <iostream>

int getGCD(int x, int y) {
	int big = (x > y) ? x : y;
	for (int i = big; i >= 1; i--) {
		if (!(x % i) && !(y % i)) {
			return i;
		}
	}
} 

int getLCM(int x, int y, int gcd) {
	return gcd * (x / gcd) * (y / gcd);
}

int main(void) {
	int x, y;

	std::cin >> x >> y;	
	int gcd = getGCD(x, y);
	std::cout << gcd << '\n' << getLCM(x, y, gcd) << std::endl;
}
