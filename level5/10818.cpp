#include <iostream>

using namespace std;

int	main(void)
{
	int *numbers;
	int count;
	int max;
	int min;
	int i;

	cin >> count;
	numbers = new int[count];
	i = 0;
	while (i < count)
	{
		cin >> numbers[i];
		i++;
	}
	i = 0;
	max = numbers[0];
	min = numbers[0];
	while (i < count)
	{
		if (numbers[i] > max)
			max = numbers[i];
		if (numbers[i] < min)
			min = numbers[i];
		i++;
	}
	cout << min << " " << max << "\n";
}
