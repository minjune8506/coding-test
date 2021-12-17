#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	int count;
	int flag = 0;
	int continual = 0;

	cin >> count;
	for (int i = 0 ; i < count ; i++)
	{
		string str;

		cin >> str;
		flag = 0;
		int j = 0;
		while (str[j])
		{
			int ret = str.find(str[j], j + 1);
			if (ret != string::npos)
			{
				if (ret != j + 1)
				{
					flag = 1;
					break ;
				}
			}
			j++;
		}
		if (flag == 0)
			continual++;
	}
	cout << continual << "\n";
}
