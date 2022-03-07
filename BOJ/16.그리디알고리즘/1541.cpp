/**
 * 1541 : 잃어버린 괄호
 * 
 * 시간제한 : 2초
 * 양수, +, -, 괄호를 가지고 식을 만들었다. 그러고 나서 괄호를 모두 지웠다.
 * 괄호를 적절히 쳐서 이 식의 값을 최소로 만드려고 한다.
 * 괄호를 적절히 넣어서 식의 값을 최소로 만드는 프로그램을 작성
 * 
 * 입력
 * 식이 주어진다('0' ~ '9', '+', '-')로 이루어져 있다.
 * 처음과 마지막 문자는 숫자이다.
 * 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다.
 * 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.
 * 
 * 출력
 * 정답 출력
 */
/**
 * 풀이
 * 
 * 난이도 : 중상!
 * 부호는 +, - 밖에 없으므로 왼쪽부터 차례대로 계산하게 된다.
 * 연속된 부호가 나올수는 없으므로, - 부호 다음에는 + 부호가 오게 된다. 이 두 부호를 묶어 +를 -로 바꿔주는 작업을 한다.
 * 즉, 한번 -가 나오게 되면 그 뒤의 수는 모두 뺴준다고 생각하면 된다.
 */
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string expression;
	int answer = 0;
	bool isMinus = false;

	cin >> expression;
	string num;

	for (int i = 0 ; i < expression.size() ; i++)
	{
		if (expression[i] == '-' || expression[i] == '+')
		{
			if (isMinus)
			{
				answer -= stoi(num);
				num = "";
			}
			else
			{
				answer += stoi(num);
				num = "";
			}
		}
		else
			num += expression[i];
		if (expression[i] == '-')
			isMinus = true;
	}
	if (num.size())
	{
		if (isMinus)
			answer -= stoi(num);
		else
			answer += stoi(num);
	}
	cout << answer << "\n";
}
