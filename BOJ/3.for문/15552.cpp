#include <iostream>

using namespace std;

int	main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int limit;
	int	*store;

	cin >> limit;
	store = new int[limit * 2];
	for (int i = 0; i < limit * 2; i += 2)
		cin >> store[i] >> store[i + 1];
	for (int i = 0; i < limit * 2; i += 2)
		cout <<  store[i] + store[i + 1] << "\n";
} 
