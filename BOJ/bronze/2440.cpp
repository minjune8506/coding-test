/**
 * 2440 : 별 찍기 - 3
 * 
 * 첫쨰 줄에는 별 N개, 둘째 줄에는 별 N - 1개, ..., N번째 줄에는 별 1개를 찍는 문제
 * 
 * 입력
 * 첫째 줄에 N (1 <= N <= 100)이 주어진다.
 * 
 * 출력
 * 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
 */
#include <iostream>

using namespace std;

int main(void)
{
	int N;

	cin >> N;
	for (int i = N ; i > 0 ; i--)
	{
		for (int j = 0 ; j < i ; j++)
			cout << "*";
		cout << "\n";
	}
}
