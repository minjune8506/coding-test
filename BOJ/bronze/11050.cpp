/**
 * 11050 이항 계수
 * 
 * 자연수 N과 정수 K가 주어졌을 떄 이항계수 (N K)를 구하는 프로그램을 작성
 * 
 * 입력
 * 첫째 줄에 N과 K가 주어진다. (1 <= N <= 10, 0 <= K <= N)
 * 
 * 출력
 * (N)를 출력한다.
 * 	K
 */
#include <iostream>

using namespace std;

int factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

int main(void)
{
	int n, k;

	cin >> n >> k;
	
	cout << factorial(n) / (factorial(k) * factorial(n - k)) << '\n';
}
