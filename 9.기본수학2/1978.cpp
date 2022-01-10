#include <iostream>

using namespace std;

int	is_prime(int n)
{
	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	int i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int cnt;
	int prime;

	cin >> cnt;
	prime = 0;
	while (cnt > 0)
	{
		int num;
		cin >> num;
		if (is_prime(num))
			prime++;
		cnt--;
	}
	cout << prime << "\n";
}
