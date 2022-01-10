#include <iostream>

using namespace std;

int	main(void)
{
	int roomId;
	int limit = 2;
	int count = 1;

	cin >> roomId;
	if (roomId == 1)
	{
		cout << 1 << "\n";
		return (0);
	}
	while (roomId >= limit)
	{
		limit += 6 * count++;
	}
	cout << count << "\n";
	return (0);
}
