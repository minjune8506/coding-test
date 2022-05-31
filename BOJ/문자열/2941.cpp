#include <iostream>
#include <string>
#include <vector>

using namespace std;

int	main(void)
{
	string croalpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	string str;

	cin >> str;
	int idx = 0;
	for (int i = 0 ; i < 8; i++)
	{
		while(1)
		{
			idx = str.find(croalpha[i]);
			if (idx == string::npos)
				break;
			str.replace(idx, croalpha[i].length(), "#");
		}
	}
	cout << str.length() << "\n";
}
