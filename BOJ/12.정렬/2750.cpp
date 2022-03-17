/**
 * 2750 : 수 정렬하기
 * 
 * 시간제한 : 1초
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 수의 개수 N(1 <= N <= 1,000)이 주어진다.
 * 둘째 줄부터 N개의 줄에는 수가 주어진다.
 * 이 수는 절댓값이 1000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
 * 
 * 출력
 * 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */
/**
 * 선택정렬 (Selection Sort)
 * 함수를 몇개 나눴더니 메모리 초과 -> sort함수 한개로 합침
 */
#include <iostream>

int N;

using namespace std;

void sort(int *ary)
{
	int min;
	int minIndex;

	for (int i = 0 ; i < N - 1 ; i++)
	{
		min = ary[i];
		minIndex = i;
		for (int j = i + 1 ; j < N ; j++)
		{
			if (ary[j] < min)
			{
				min = ary[j];
				minIndex = j;
			}
		}
		if (min != ary[i])
		{
			int temp;

			temp = ary[minIndex];
			ary[minIndex] = ary[i];
			ary[i] = temp;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	int ary[N];
	for (int i = 0 ; i < N ; i++)
		cin >> ary[i];
	sort(ary);
	for (int i = 0 ; i < N ; i++)
		cout << ary[i] << "\n";
}
