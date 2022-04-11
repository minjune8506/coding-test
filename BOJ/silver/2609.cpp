/**
 * 2609 : 최대공약수와 최소공배수
 * 
 * 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을
 * 작성하시오.
 * 
 * 입력
 * 첫째 줄에는 두 개의 자연수가 주어진다.
 * 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.
 * 
 * 출력
 * 첫째 줄에는 입력으로 주어진 두 수의 최대공약수를
 * 둘째 줄에는 입력으로 주어진 두 수의 최소공배수를 출력한다.
 */
/**
 * 풀이
 * Brute-Force
 * 	- 최소공배수에서 난관에 부딪힘
 *  - O(N)의 시간이 걸리고 아마 시간초과가 날 듯
 * 유클리드 호제법
 * 	- A와 B의 최대공약수는 B와 r의 최대공약수와 같다.
 *  - r은 A를 B로 나눈 나머지
 */
#include <iostream>

using namespace std;

// 최대 공약수 : the greatest common denominator
int getGCD(int a, int b)
{
	int r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

// 최소 공배수 : the least common multiple
int getLCM(int a, int b, int gcd)
{
	return (a * b / gcd);
}

int main(void)
{
	int a, b;

	cin >> a >> b;
	int gcd = getGCD(a, b);
	cout << gcd << '\n';
	cout << getLCM(a, b, gcd) << '\n';
}
