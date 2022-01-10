#include <iostream>
#include <cstring>

using namespace std;

int		main(void)
{
	int ary[10];
	int	ret[42];
	int count = 0;

	memset(ret, 0, sizeof(int) * 42);
	for (int i = 0; i < 10; i++)
	{
		cin >> ary[i];
		ary[i] = ary[i] % 42;
		ret[ary[i]]++;
	}
	for (int i = 0; i < 42; i++)
		if (ret[i] != 0)
			count++;
	cout << count << "\n";
}
