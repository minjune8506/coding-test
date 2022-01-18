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
