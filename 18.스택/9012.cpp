/*
9012 : 괄호
입력은 T개의 테스트 데이터로 주어진다.
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다.
각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 

Valid : (()) ()() (()()) ..
Invalid : (() (())(( ())() ..
*/

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int check_ps(stack<char> s, char *str)
{
	for (int i = 0 ; i < strlen(str) ; i++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')')
		{
			if (!s.empty() && s.top() == '(')
				s.pop();
			else
				return (EXIT_FAILURE);
		}
	
	}
	if (s.empty())
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	int T;
	char *str;
	stack<char> s;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	str = new char[51];
	while (T > 0)
	{
		memset(str, '0', sizeof(char) * 51);
		cin >> str;
		if (check_ps(s, str))
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
		T--;
	}
	return (0);
}
