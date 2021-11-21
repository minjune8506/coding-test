#include <iostream>

using namespace std;

int	main(void)
{
	int num;
	int sum;
	int firstNum;
	int newNum;
	int count;

	cin >> firstNum;
	num = firstNum;
	newNum = -1;
	count = 0;
	while (1)
	{
		if (newNum == firstNum)
			break ;
		if (num < 10)
			sum = 0 + num;
		else
			sum = num / 10 + num % 10;
		newNum = num % 10 * 10 + sum % 10;
		num = newNum;
		count++;
	}
	cout << count << "\n";
}
