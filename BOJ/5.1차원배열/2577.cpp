#include <iostream>
#include <cstring>

using namespace std;

int	main(void)
{
	int a, b, c;
	int ret;
	int ary[10];

	cin >> a >> b >> c;
	ret = a * b * c;
	memset(ary, 0, sizeof(int) * 10);
	while (ret != 0)
	{
		ary[ret % 10] += 1;
		ret /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << ary[i] << "\n";
}
