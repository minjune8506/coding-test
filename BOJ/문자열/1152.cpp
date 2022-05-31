#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int	split(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (!str[i])
			break ;
		while (isalpha(str[i]) && str[i])
			i++;
		count++;
		while (str[i] == ' ' && str[i])
			i++;
	}
	return (count);
}

int	main(void)
{
	char str[1000000];

	cin.getline(str, 10000000, '\n');
	cout << split(str) << "\n";
	return (0);
}
