#include <iostream>

using namespace std;

int	main(void)
{
	int count;
	int studentNum;
	int *scores;
	int avg;
	int	over_than_avg;

	cin >> count;
	for (int i = 0 ; i < count ; i++)
	{
		int sum = 0;
		over_than_avg = 0;
		cin >> studentNum;
		scores = new int[studentNum];
		for (int j = 0; j < studentNum; j++)
		{
			cin >> scores[j];
			sum += scores[j];
		}
		avg = sum / studentNum;
		for (int j = 0; j < studentNum; j++)
		{
			if (scores[j] > avg)
				over_than_avg++;
		}
		cout << fixed;
		cout.precision(3);
		cout << (double)over_than_avg / studentNum * 100 << '%' << "\n";
		delete [] scores;
	}
}
