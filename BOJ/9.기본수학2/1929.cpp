/**
 * 1929 : 소수 구하기
 * 
 * 시간제한 : 2초
 * M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다.
 * (1 <= M <= N <= 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
 * 
 * 출력
 * 한 줄에 하나씩, 증가하는 순서대로 소수 출력
 */
#include <iostream>

using namespace std;

int M, N;

void eratos_sieve(int *numbers)
{
	// 2부터 N까지 소수가 아닌 수들을 지워나간다.
	for (int i = 2 ; i < N + 1 ; i++)
	{
		if (numbers[i] == 0)
			continue ;
		for (int j = i + i ; j < N + 1 ; j += i)
			numbers[j] = 0;
	}

	// 출력
	for (int i = M ; i < N + 1 ; i++)
	{
		if (i == 1)
			continue ;
		if (numbers[i])
			cout << numbers[i] << "\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력 & 메모리 할당
	cin >> M >> N;
	int *numbers = new  int[N + 1];
	for (int i = 2 ; i < N + 1 ; i++)
		numbers[i] = i;
	
	// 에라토스테네스의 체(소수 판별 알고리즘)
	eratos_sieve(numbers);

	// 메모리 해제
	delete [] numbers;
}
