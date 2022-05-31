/**
 * 9184 : 신나는 함수 실행
 * 
 * if (a <= 0 || b <= 0 || c <= 0)
 * 		return 1;
 * if (a > 20 || b > 20 || c > 20)
 * 		return w(20, 20, 20);
 * if (a < b && b < c)
 * 	return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
 * 
 * else
 * 	return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
 * 
 * 위의 함수를 구현하는 것은 쉽지만 값을 구하는데 시간이 너무 많이 걸린다.
 * a, b, c가 주어졌을때 w(a, b, c)를 출력하는 프로그램을 작성하시오.
 * 
 * 시간제한 : 1초
 * 
 * 입력
 * 
 * 세 정수 a, b, c로 이루어져 있고, 한줄에 하나씩 주어진다.
 * 입력의 마지막은 -1 -1 -1이다.
 * 
 * 출력
 * 
 * w(a, b, c)를 출력한다.
 * 
 * -50 <= a, b, c <= 50
 */

/**
 * 풀이
 * 
 * 기존 함수에서 최적화 할 요소를 찾는다.
 * 반복되는 계산은 dp 배열에 저장해 놓음으로써 반복적인 계산을 막는다.
 * 
 */
#include <iostream>

int dp[21][21][21] = {0, };

int solve(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
	{
		if (!dp[20][20][20]) // 20 20 20 칸에 값이 없다면 계산해서 채워넣음
			dp[20][20][20] = solve(20, 20, 20);
		return dp[20][20][20]; // 아니면 20 20 20 칸의 값을 반환
	}
	if (dp[a][b][c]) // 기존의 계산한 값이 있다면
		return dp[a][b][c]; // 기존 값 반환
	if (a < b && b < c)
	{
		dp[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c); // 계산 값 저장
		return dp[a][b][c];
	}
	dp[a][b][c] =  solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1); // 계산 값 저장
	return (dp[a][b][c]);
}

int main(void)
{
	int a, b, c;

	dp[0][0][0] = 1;

	while (true)
	{
		// input
		std::cin >> a >> b >> c;

		// break
		if (a == -1 && b == -1 && c == -1)
			break ;

		// output
		std::cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
	}
}
