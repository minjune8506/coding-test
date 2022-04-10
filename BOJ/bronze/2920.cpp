/**
 * 2920 : 음계
 * 
 * 다장조는 c d e f g a b C 총 8개의 음으로 이루어져 있다.
 * 이 문자에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다.
 * c = 1, d = 2 ... C = 8로 바꾼다.
 * 1부터 8까지 차례대로 연주하면 ascending
 * 8부터 1까지 차례대로 연주하면 descending
 * 둘다 아니라면 mixed이다.
 * 연주한 순서가 주어졌을 때, 이것이 ascendiing인지, descending인지
 * mixed인지를 판별하는 프로그램을 작성하시오
 * 
 * 입력
 * 첫째 줄에 8개 숫자가 주어진다.
 * 이 숫자는 문제 설명에서 설명한 음이며, 1부터 8까지 숫자가 한 번씩 등장한다.
 * 
 * 출력
 * ascending, descending, mixed 중 하나를 출력
 */
#include <iostream>
#include <vector>

using namespace std;

bool isAscending(vector<int> &scale)
{
	for (int i = 0 ; i < scale.size() - 1 ; i++)
	{
		if (scale[i] > scale[i + 1])
			return false;
	}
	return true;
}

bool isDescending(vector<int> &scale)
{
	for (int i = 0 ; i < scale.size() - 1 ; i++)
	{
		if (scale[i] < scale[i + 1])
			return false;
	}
	return true;
}

int main(void)
{
	vector<int> scale;

	for (int i = 0 ; i < 8 ; i++)
	{
		int num;

		cin >> num;
		scale.push_back(num);
	}
	if (isAscending(scale))
		cout << "ascending" << '\n';
	else if (isDescending(scale))
		cout << "descending" << '\n';
	else
		cout << "mixed" << '\n';
}
