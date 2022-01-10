/*
** 2217 로프
** 첫째줄에 로프의 개수 N이 주어진다.
** k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때,
** 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸린다.
** 각 로프들에 대한 정보가 주어졌을 때, 이 로프들로 들 수 있는 물체의
** 최대 중량을 구해내는 프로그램.
** 모든 로프를 사용할 필요는 없다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int	main(void)
{
	int N; // 로프의 개수
	int *rope; // 각 로프가 버틸 수 있는 최대 중량
	int max = 0; // 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량

	cin >> N;
	rope = new int[N];
	for (int i = 0 ; i < N ; i++)
		cin >> rope[i];
	
	sort(rope, rope + N, greater<int>()); // 내림차순으로 정렬
	for (int i = 0 ; i < N ; i++)
	{
		unsigned long long sum = rope[i] * (i + 1);
		if (sum > max)
			max = sum;
	}
	cout << max <<  "\n";
	delete [] rope;
	return (0);
}
