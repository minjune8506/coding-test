#include <iostream>

using namespace std;

int	main(void)
{
	int i;
	int *store;

	cin >> i;
	store = new int[i * 2];
	for (int j = 0 ; j != i * 2 ; j += 2)
		cin >> store[j] >> store[j + 1];
	for (int j = 0 ; j != i * 2 ; j += 2)
		cout << store[j] + store[j + 1] << endl;
}
