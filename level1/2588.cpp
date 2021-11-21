#include <iostream>

using namespace std;

int	main(void)
{
	int a, b;

	cin >> a >> b;
	cout << b % 10 * a << endl;
	cout << b / 10 % 10 * a << endl;
	cout << b / 10 / 10 % 10 * a << endl;
	cout << a * b << endl;
}
