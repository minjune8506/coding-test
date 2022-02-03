/*
* 1009 : 분산처리
* 각 컴퓨터에 1번 ~ 10번까지의 번호를 부여하고
* 1번 데이터 -> 1번 컴퓨터
* 10번 데이터 -> 10번 컴퓨터
* 11번  데이터 -> 1번 컴퓨터
* 데이터의 개수는 항상 a^b개의 형태이다.
* 마지막 데이터가 처리될 컴퓨터의 번호를 구하라
*
* 입력 : 테스트 케이스 T가 주어진다. 다음줄에 a와 b가 주어진다.
* 출력 : 마지막 데이터가 처리되는 컴퓨터 번호를 출력
*/

/*
* 풀이 방법
* 컴퓨터는 10대 고정되어있다.
* a^b의 값이 10보다 크면 10으로 나눈 나머지만 유지한다.
* ex) 2^7 => 2 4 8 16(6) 12(2) 4 8 -> 8
* 10, 20, 30값 -> 나머지가 0이면 10출력.
*/

#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;
	for (int i = 0 ; i < T ; i++)
	{
		int a, b;
		int store = 1;

		cin >> a >> b;
		for (int j = 0 ; j < b ; j++)
		{
			store *= a;
			if (store > 10)
				store %= 10;
		}
		if (store == 0)
			cout << 10 << "\n";
		else
			cout << store << "\n";
	}
}
