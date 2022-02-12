/**
 * 1003 : 피보나치 함수
 * 
 * 시간제한 0.25초
 * 다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.
 * 
 * int fibonacci(int n) {
 * 	if (n == 0) {
 * 		printf("0");
 * 		return (0);
 *	}
 * else if (n == 1) {
 * 	printf("1");
 * 	return (1);
 * }
 * else
 * 	return fibonacci(n - 1) + fibonacci(n - 2);
 * }
 *
 * fibonacci(N)을 호출했을떄 0과 1이 각각 몇번 출력되는지 구하는 프로그램을 작성해라
 * 
 * 입력
 * 첫째줄에 테스트 케이스 개수 T가 주어진다.
 * 각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.
 * 
 * 출력
 * 각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
 */

/**
 * 풀이
 * 
 * 기존 피보나치 함수를 써서 0과 1의 갯수를 구하면 시간초과가 난다. 0.25초이므로 조금 더 효율적인 방법이 필요하다.
 * fib(0) -> f(0) : 1 0
 * fib(1) -> f(1) : 0 1
 * fib(2) -> fib(1) + fib(0) : 1 1 
 * fib(3) -> fib(2) + fib(1) -> fib(1) + fib(0) + fib(1) : 1 2
 * fib(4) -> fib(3) + fib(2) -> fib(2) + fib(1) + fib(1) + fib(0)
 * -> fib(1) + fib(0) + fib(1) + fib(1) + fib(0) : 2 3
 * 
 * DP를 사용해 결과를 저장한다.
 * fib (0) : 1 0 -> 0
 * fib (1) : 0 1 -> 1
 * fib (2) : 1 1 -> 1
 * fib (3) : 1 2 -> 2
 * fib (4) : 2 3 -> 3
 * fib (5) : 3 5 -> 5
 * fib (6) : 5 8 -> 8
 * fib (7) : 8 13 -> 13
 * 
 * zero = dp[n - 1];
 * one = dp[n];
 */

#include <iostream>

using namespace std;

int t, n;
int dp[42];

void solve(int n, int &zero, int &one)
{
	dp[0] = 0;
	dp[1] = 1;

	if (n == 0)
	{
		zero++;
		return ;
	}
	else if (n == 1)
	{
		one++;
		return ;
	}
	for (int i = 2; i <= n ; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	zero = dp[n -1];
	one = dp[n];
}

int main(void)
{
	int zero, one;
	cin >> t;

	for (int i = 0 ; i < t ; i++)
	{
		zero = 0, one = 0;
		cin >> n;
		solve(n, zero, one);
		cout << zero << " " << one << "\n";
	}
}
