/*
** 4949 균형잡힌 세상
** 문자열에 포함되는 괄호 : ( ) [ ]
** 괄호들끼리 짝이 맞아야 한다.
** 입력  - 한줄 or 여러줄의 문자열
**		 - 각 문자열은 영문 알파벳, 공백, ( ) [ ] 등으로 이루어진다.
** 		 - 입력의 종료조건으로 맨 마지막에 점(.)하나가 들어온다.
** 풀이
** 1. 문자열을 입력 받는다.
** 2. 문자열의 크기가 1이고 '.'인 경우 반복문을 탈출 & 프로그램 종료
** 3. 문자열이 '.'이 아닐때 까지 괄호를 검사한다.
** 4. '(' '[' 괄호일 경우, 스택에 push
** 5. ')' ']' 괄호일 경우, 스택이 비어있는지 확인하고, 짝이 맞는 괄호가 스택의 최상단에 위치하는지 확인한다.
** 6. 문자열에 '.'이 나와서 반복문이 끝났다면, 스택이 비어있는지 확인한다. 
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int check(string str)
{
	stack<char> s;
	int i = 0;

	while (str[i] != '.')
	{
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == '[')
			s.push(str[i]);
		else if (str[i] == ')')
		{
			if (s.empty() || s.top() != '(')
				return (EXIT_FAILURE);
			else
				s.pop();
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
				return (EXIT_FAILURE);
			else
				s.pop();
		}
		i++;
	}
	if (!s.empty())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	string str;

	while (1)
	{
		getline(cin, str);
		if (str.size() == 1 && str[0] == '.')
			break;
		if (check(str))
			cout << "no" << "\n";
		else
			cout << "yes" << "\n";
	}
	return (0);
}
