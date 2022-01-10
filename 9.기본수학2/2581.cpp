#include <iostream>

using namespace std;

int is_prime(int num)
{
	if (num <= 1)
		return (0);
	else if (num == 2)
		return (1);
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return (0);
	}
	return (1);
}

int	main(void)
{
	int m, n;
	int sum = 0;
	int min;
	int flag = 0;

	cin >> m >> n;
	while (m <= n)
	{
		if (is_prime(m))
		{
			if (!flag)
			{
				min = m;
				flag = 1;
			}
			sum += m;
		}
		m++;		
	}
	if (sum == 0)
		cout << -1 << "\n";
	else
	{
		cout << sum << "\n";
		cout << min << "\n";
	}
	return (0);
}
