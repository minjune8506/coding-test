#include <iostream>

using namespace std;

int main(void)
{
	int hour;
	int minute;
	int time;

	cin >> hour >> minute;
	time = hour * 60 + minute;
	time -= 45;
	if (time < 0)
	{
		hour = 23;
		minute = time + 60;
	}
	else
	{
		hour = time / 60;
		minute = time % 60;
	}
	cout << hour << " " << minute << endl;
}
