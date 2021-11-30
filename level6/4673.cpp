#include <iostream>

using namespace std;

int self_num(int n)
{
	int i = 0;
	int d;

	while(i < n)
	{
		int num = i;
		d = i;
		while (num > 0)
		{
			d = d + num % 10;
			num /= 10;
		}
		if (d == n)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int n = 1;
	while (n <= 10000)
	{
		if (self_num(n) == 1)
			cout << n << "\n";
		n++;
	}
	return (0);
}
