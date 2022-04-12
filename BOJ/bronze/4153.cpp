/**
 * 4153 : 직각삼각형
 * 
 * 각 변들의 길이가 3, 4, 5인 삼각형이 직각삼각형인 것을 알아냈다.
 * 주어진 세 변의 길이로 삼각형이 직각인지 아닌지 구분하시오.
 * 
 * 입력
 * 여러개의 테스트케이스로 주어지며 마지막 줄에는 0 0 0 이 입력된다.
 * 각 테스트 케이스는 모두 30,000보다 작은 양의 정수로 주어지며,
 * 각 입력은 변의 길이를 의미한다.
 * 
 * 출력
 * 각 입력에 대해 직각삼각형이 맞다면 "right" 아니면 "wrong"을 출력한다.
 */
// 풀이 : 피타고라스의 정리

#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;

	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break ;
		if (a * a == b * b + c * c)
			cout << "right" << '\n';
		else if (b * b == a * a + c * c)
			cout << "right" << '\n';
		else if (c * c == a * a + b * b)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
}
