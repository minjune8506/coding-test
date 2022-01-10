#include <iostream>
#include <cstring>

using namespace std;

int	main(void)
{
	int num;
	char *str;
	
	cin >> num;
	str = new char[80];
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		int	count = 0;
		int sum = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'O')
				count++;
			else
				count = 0;
			sum += count;
		}
		cout << sum << "\n";
	}
	 delete [] str;
}
