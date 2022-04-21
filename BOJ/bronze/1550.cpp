/**
 * 1550 : 16진수
 * 
 * 16진수 수를 입력받아서 10진수로 출력하는 프로그램을 작성
 * 
 * 입력
 * 16진수 수가 주어진다.
 * 최대 길이는 6글자이다.
 * 
 * 출력
 * 16진수 수를 10진수로 변환해 출력한다.
 * 
 * 16진수는 0 ~ 9 A ~ F로 이루어져 있다.
 * 문자열의 처음부터 시작해서 16씩 곱해나가면서 숫자를 더해준다.
 * atoi랑 같은 원리로 해결한다.
 */
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	int num = 0;

	cin >> str;
	for (int i = 0 ; i < str.size() ; i++) {
		num *= 16;
		if (str[i] >= 'A' && str[i] <= 'F') {
			num += (str[i] - 'A' + 10);
		}
		else {
			num += (str[i] - '0');
		}
	}
	cout << num << '\n';
}
