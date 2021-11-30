#include <iostream>
#include <cstring>

using namespace std;

int get_length(int n)
{
	int length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int check_num(int n)
{
	int i = 0;
	int *buf;
	int length = get_length(n);
	int diff = 0;

	buf = new int[length];
	memset(buf, 0, sizeof(int) * length);
	while (n > 0)
	{
		buf[i] = n % 10;
		n /= 10;
		i++;
	}
	diff = buf[1] - buf[0];
	i = 1;
	while (i < length)
	{
		if ((buf[i] - buf[i - 1]) != diff)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int num;
	int i = 1;
	int count = 0;

	cin >> num;
	while (i <= num)
	{
		if (check_num(i))
			count++;
		i++;
	}
	cout << count << "\n";
}
