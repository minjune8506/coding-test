/**
 * 2231 : 분해합
 * 
 * 어떤 자연수 N이 있을 떄, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다.
 * 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.
 * 245의 분해합은 256 (= 245 + 2 + 4 + 5)이 된다.
 * 따라서 245는 256의 생성자가 된다. 물론, 어떤 자연수의 경우에는 생성자가 없을 수 있다.
 * 반대로, 생성자가 여러개인 자연수도 있을 수 있다.
 * 자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성
 * 
 * 입력
 * 자연수 N (1 <= N <= 1,000,000)이 주어진다.
 * 
 * 출력
 * 답을 출력한다. 생성자가 없는 경우 0을 출력
 */
#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0 ; i < N ; i++)
	{
		int j = i;
		int constructor = 0;
		while (j > 0)
		{
			constructor += j % 10;
			j /= 10;
		}
		if (i + constructor == N)
		{
			cout << i << "\n";
			return (0);
		}
	}
	cout << 0 << "\n";
}
