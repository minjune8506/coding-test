/**
 * 10989 : 수 정렬하기 3
 * 
 * 시간제한 : 5초, 메모리 제한 : 8MB
 * N개의 수가 주어졌을 때 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
 * 
 * 입력
 * 수의 개수 N (1 <= N <= 10,000,000)이 주어진다.
 * N개의 줄에 수가 주어진다.
 * 이 수는 10,000보다 작거나 같은 자연수이다.
 * 
 * 출력
 * N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
 */
// 입력의 갯수만큼 배열을 만들어서 담으면 메모리 초과가 난다.
// 10000000 * 4 = 40000000 -> 38 MB
// 10000보다 작거나 같은 자연수라는 조건을 이용해서
// 10001개의 배열사이즈에 counting sort를 적용한다.
// 10,000 * 4 => 40000 -> 40 KB
#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int *temp = new int[10001];
	for (int i = 0 ; i < 10001 ; i++)
		temp[i] = 0;

	cin >> N;
	for (int i = 1 ; i < N + 1 ; i++)
	{
		int num;
		
		cin >> num;
		temp[num]++;
	}
	for (int i = 1 ; i < 10001 ; i++)
	{
		if (!temp[i])
			continue ;
		for (int j = 0 ; j < temp[i] ; j++)
			cout << i << "\n";
	}
}
