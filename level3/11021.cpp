#include <iostream>

using namespace std;

int	main(void)
{
	int num;
	int *store;

	cin >> num;
	store = new int[num * 2];

	for (int i = 0; i < num * 2; i+= 2)
		cin >> store[i] >> store[i + 1];
	for (int i = 0; i < num * 2 ; i += 2)
		cout << "Case #" << i / 2 + 1 << ": " << store[i] + store[i + 1] << "\n";
	delete [] store;
}
