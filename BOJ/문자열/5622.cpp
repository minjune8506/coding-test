#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	string str;
	int i = 0;
	int total = 0;

	cin >> str;
	while(str[i])
	{
		int count;
		int time;

		if (str[i] >= 'A' && str[i] <= 'O') 
		{
			count = str[i] - 'A';
			time = count / 3 + 3;
			total += time;
		}
		else if (str[i] >= 'P' && str[i] <= 'S')
			total += 8;
		else if (str[i] >= 'T' && str[i] <= 'V')
			total += 9;
		else
			total += 10;
		i++;
	}
	cout << total << "\n";
}
