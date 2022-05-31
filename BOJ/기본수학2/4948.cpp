/**
 * 4948 : 베르트랑 공준
 * 
 * 베르트랑 공준은
 * 임의의 자연수 n에 대하여, n보다 크고 2n 보다 작거나 같은 소수는 적어도
 * 하나는 존재한다는 내용을 담고 있다.
 * 자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.
 * 
 * 입력
 * 여러 개의 테스트 케이스로 이루어져 있다.
 * 각 케이스는 n을 포함하는 한 줄로 이루어져 있다.
 * 입력의 마지막에는 0이 주어진다.
 * 
 * 출력
 * 각 테스트케이스에 대해, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력
 * ( 1 <= n <= 123,456)
 */
// 2 3 5 7 11 13 17 19 23 29 31 ...
#include <iostream>

using namespace std;

void bertrand(int limit, int *numbers)
{
	int primeCount = 0;

	for (int i = 2 ; i < limit * 2 + 1 ; i++)
	{
		if (!numbers[i])
			continue ;
		for (int j = i + i ; j < limit * 2 + 1 ; j += i)
			numbers[j] = 0;
	}
	for (int i = limit + 1 ; i < limit * 2 + 1 ; i++)
	{
		if (i <= 1)
			continue ;
		if (numbers[i])
			primeCount++;
	}
	cout << primeCount << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int limit = -1;

	while (limit)
	{
		cin >> limit;
		if (!limit)
			break ;
		int *numbers = new int[limit * 2 + 1];
		for (int i = 2 ; i < limit * 2 + 1 ; i++)
			numbers[i] = i;
		bertrand(limit, numbers);
		delete [] numbers;
	}
	return (0);
}
