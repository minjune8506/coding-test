/**
 * 2525 : 오븐 시계
 * 
 * 인공지능 오븐을 개발하려고 한다.
 * 사용법은 적당한 양의 오리 훈제 재료를 오븐에 넣으면 된다. 
 * 인공지능 오븐은 오븐구이가 끝나느 시간을 분단위로 자동 계산한다.
 * 오븐의 앞면에는 요리가 끝나느 시각을 알려주는 디지털 시계가 있다.
 * 훈제 오리구이를 시작하는 시각과 오븐구이를 하는데 필요한 시간이 분단위로
 * 주어질때, 오븐구이가 끝나느 시각을 계산하는 프로그램을 작성하시오.
 * 
 * 입력
 * 첫째줄 -> 현재 시각 (시 A(0 <= A <= 23) 와 분 B(0 <= B <= 59)가 정수로 주어진다)
 * 두번째 줄 -> 요리하는데 필요한 시간 C(0 <= C <= 1000)가 분단위로 주어진다.
 * 
 * 출력
 * 죵료되는 시각의 시와 분을 공백을 사이에 두고 출력한다.
 * (시는 0 ~ 23까지의 정수, 분은 0 ~ 59까지의 정수)
 * 시계는 23시 59분에서 1분이 지나면 0시 0분이 된다.
 */
#include <iostream>

using namespace std;

int main(void)
{
	int hour;
	int minute;
	int cookTime;

	cin >> hour >> minute >> cookTime;
	if (minute + cookTime >= 60)
	{
		hour += (minute + cookTime) / 60;
		if (hour >= 24)
			hour %= 24;
		minute = (minute + cookTime) % 60;
	}
	else
		minute += cookTime;
	cout << hour << " " << minute << "\n";
}
