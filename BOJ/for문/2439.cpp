#include <iostream>
#include <cstring>

using namespace std;

int	main(void)
{
	int count;
	char *str;

	cin >> count;
	for (int i = 1; i <= count; i++)
	{
		str = new char[count + 1];
		memset(str, ' ', count);
		str[count] = '\0';
		for (int j = 1; j <= i; j++)
			str[count - j] = '*';
		cout << str << "\n";
		delete [] str;
	}
}
