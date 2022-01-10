#include <iostream>

using namespace std;

int	main(void)
{
	int	num;
	int	i;

	cin >> num;

	for (int i = 2 ; num > 1 ; ) {
		if (num % i == 0)
		{
			cout << i << "\n";
			num /= i;
		}
		else
			i++;
	}
}
