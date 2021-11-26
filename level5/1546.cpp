#include <iostream>

using namespace std;

int	main(void)
{
	double *scores;
	double avg;
	int	num;
	int max;

	max = 0;
	avg = 0;
	cin >> num;
	scores = new double[num];
	for (int i = 0 ; i < num ; i++)
	{
		cin >> scores[i];
		if (scores[i] > max)
			max = scores[i];
	}
	for (int i = 0 ; i < num ; i++)
	{
		scores[i] = scores[i] / max * 100;
		avg += scores[i];
	}
	avg /= num;
	cout << avg << "\n";
}
