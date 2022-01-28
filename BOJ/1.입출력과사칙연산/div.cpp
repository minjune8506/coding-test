#include <iostream>
#include <stdio.h>
using namespace std;

// int		main(void)
// {
// 	double a;
// 	double b;

// 	scanf("%lf %lf", &a, &b);
// 	printf("%.13lf", a / b);
// 	return 0;
// }
int	main(void)
{
	int num1;
	int num2;

	cout << fixed;
	cout.precision(10);

	cin >> num1 >> num2;
	cout << (double)num1 / num2 << endl;
}
