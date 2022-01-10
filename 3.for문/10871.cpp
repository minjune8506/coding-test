#include <iostream>

using namespace std;

int	main(void)
{
	int count;
	int offset;
	int *store;

	cin >> count >> offset;
	store = new int[count];
	for (int i = 0; i < count; i++)
		cin >> store[i];
	for (int i = 0; i < count; i++)
	{
		if (store[i] < offset)
			cout << store[i] << " ";
	}
	cout << "\n";
}
