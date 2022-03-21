/**
 * 1920 : 수 찾기
 * 
 * N개의 정수 A[1], A[2], ..., A[N]이 주어져 있을 때,
 * 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째 줄에 자연수 N (1 <= N <= 100,000)이 주어진다.
 * 다음 줄에는 N개의 정수 A[1], A[2], ..., A[N]이 주어진다.
 * 다음 줄에는 M (1 <= M <= 100,000)이 주어진다.
 * 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다.
 * 모든 정수의 범위는 -2^31 보다 크거나 같고, 2^31보다 작다.
 * 
 * 출력
 * M개의 줄에 답을 출력한다. 존재하면 1, 존재하지 않으면 0을 출력
 */
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100001];

bool BinarySearch(int start, int length, int key)
{
	int end = length - 1;
	int mid;

	while (end - start >= 0)
	{
		mid = (start + end) / 2;
		if (key == A[mid])
			return (true);
		if (key > A[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (false);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int key;
	
	cin >> N;
	for (int i = 0 ; i < N ; i++)
		cin >> A[i];
	sort(A, A + N);
	cin >> M;
	for (int i = 0 ; i < M ; i++)
	{
		cin >> key;
		cout << BinarySearch(0, N, key) << "\n";
	}
	return (0);
}
