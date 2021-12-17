#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	int num;

	cin >> num;
	for (int i = 0 ; i < num ; i++)
	{
		int count;
		string str;

		cin >> count >> str;
		for (int i = 0 ; i < str.length(); i++)
		{
			int j = 0;
			while(j < count)
			{
				cout << str[i];
				j++;
			}
		}
		cout << "\n";
	}
}
