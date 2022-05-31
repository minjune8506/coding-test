#include <iostream>

using namespace std;

int	main(void)
{
	int ary[9];
	int max;

	for (int i = 0 ; i < 9 ; i++)
		cin >> ary[i];
	max = ary[0];
	for (int i = 0 ; i < 9 ; i++)
		if (max < ary[i])
			max = ary[i];
	cout << max << "\n";
	for (int i = 0 ; i < 9 ; i++)
		if (max == ary[i])
		{
			cout << i + 1 << "\n";
			break ;
		}
	return (0);		
}
