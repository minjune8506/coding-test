/**
 * 1259 : 펠린드롬수
 * 
 * 어떤 단어를 뒤에서부터 읽어도 똑같다면 그 단어를 팰린드롬이라고 한다.
 * 수도 펠린드롬으로 취급할 수 있다.
 * 수의 숫자들을 뒤에서 부터 읽어도 같다면 그 수는 팰린드롬수다.
 * 121, 12421 등은 팰린드롬수다.
 *
 * 입력
 * 여러 개의 테스트 케이스로 이루어져 있으며,
 * 각 줄마다 1 이상 99999 이하의 정수가 주어진다.
 * 입력의 마지막 줄에는 0이 주어지며, 이 줄은 문제에 포함되지 않는다.
 * 
 * 출력
 * 각 줄마다 주어진 수가 팰린드롬수면 yes, 아니면 no를 출력한다.
 */

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string num;
		int flag = 0;

		cin >> num;
		if (num == "0")
			break ;
		for (int i = 0 ; i < num.size() / 2 ; i++)
		{
			if (num[i] != num[num.size() - 1 - i])
			{
				cout << "no" << '\n';
				flag = 1;
				break ;
			}
		}
		if (!flag)
			cout << "yes" << '\n';
	}
	return (0);
}
