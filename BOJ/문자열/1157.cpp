#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int	main(void)
{
	int alpha[26];
	string str;

	cin >> str;
	memset(alpha, 0, sizeof(int) * 26);
	for (int i = 0 ; i < str.size(); i++)
		str[i] = tolower(str[i]);
	for (int i = 0 ; i < str.length() ; i++)
	{
		if (isalpha(str[i]))
			alpha[str[i] - 'a']++;
	}
	int max = alpha[0];
	int max_index = 0;
	for (int i = 0 ; i < 26; i++)
		if (alpha[i] > max)
		{
			max = alpha[i];
			max_index = i;
		}
	for (int i = 0 ; i < 26 ; i++)
	{
		if (i != max_index)
			if (max <= alpha[i])
			{
				cout << "?" << "\n";
				return (0);
			}
	}
	cout << (char)('A' + max_index) << endl;
}
