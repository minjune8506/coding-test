#include <iostream>

using namespace std;

int	main(void)
{
	int fixed;
	int labor;
	int price;

	cin >> fixed >> labor >> price;
	if (labor >= price)
	{
		cout << -1 << "\n";
		return (0);
	}
	int num = fixed / (price - labor) + 1;
	cout << num << "\n";
	return (0);
}
