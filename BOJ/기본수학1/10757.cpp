/**
 * 10757 : 큰 수 A+B
 * 
 * 두 정수 A와 B를 입력받은 다음, A + B를 출력하는 프로그램을 작성
 * 
 * 입력
 * A 와 B가 주어진다. (0 < A,B < 10^10000)
 * 
 * 출력
 * 첫째 줄에 A + B를 출력
 */
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string a, b;
	string result = "";

	cin >> a >> b;
	int i = a.size() - 1, j = b.size() - 1;
	int tmp = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0) // a 문자열이 남아 있는 경우
			tmp += (a[i] - '0'); 
		if (j >= 0) // b 문자열이 남아있는 경우
		 	tmp += (b[j] - '0');
		if (tmp >= 10) // a + b가 10이 넘는 경우
		{
			char ch = ('0' + (tmp % 10)); // 나머지만 더해준다.
			result = ch + result;
			tmp /= 10; // 10으로 나눠서 다음자릿수에 더해줄 값을 구한다.
		}
		else // 10을 넘지 않는 경우
		{
			char ch = '0' + tmp;
			result = ch + result; // 그냥 더한다.
			tmp = 0; // 다음 자릿수에 더할 수는 없으니 0으로 바꿔준다.
		}
		i--; j--;
	}
	if (tmp > 0) // 다 더했는데 tmp가 0이 아닌경우 -> 마지막 덧셈이 10을 넘는다.
	{
		char ch = '0' + tmp;
		result = ch + result; // 자릿수 하나 추가
	}
	cout << result << '\n';
}
