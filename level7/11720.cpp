#include <iostream>

using namespace std;

int	main(void)
{
	int n;
	char num;
	int sum = 0;

	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> num;
		if (num >= '0' && num <= '9')
			sum = sum + num - '0';
	}
	cout << sum << "\n";

}
