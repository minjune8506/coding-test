/* 1193 : 분수 찾기
** Key  1. 몇번째 지그재그에 있는지 파악해야 한다. (i번째 줄)
**		2. 홀수번째, 짝수번째 줄 마다 규칙이 다르다.
**		3. 홀수 줄 : (i - N + 1) / N
**		4. 짝수 줄 : N / (i - N + 1)
*/

#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int i = 1;
	while (N > i)
	{
		N -= i;
		i++;
	}
	if (i % 2 == 1)
		cout << i - N + 1 << '/' << N << endl;
	else
		cout << N << '/' << i - N + 1<< endl;
}
