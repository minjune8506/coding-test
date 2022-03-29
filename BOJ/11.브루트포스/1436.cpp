/**
 * 1436 : 영화감독 숌
 * 
 * 666은 종6말을 나타내는 숫자라고 한다.
 * 종말의 숫자란 어떤 수에 6이 적어도 3개이상 연속으로 들어가는 수를 말한다.
 * 제일 작은 종말의 숫자는 666, 1666, 2666, ... 과 같다.
 * 숌은 영화 제목을 666, 1666, 2666, 이렇게 이름을 지을 것이다.
 * 일반화해서 생각하면 N번째 영화 제목은 (N번째로 작은 종말의 숫자)와 같다
 * N번째 영화 제목에 들어간 숫자를 출력하는 프로그램을 작성하시오.
 * 
 * 입력
 * N이 주어진다. N은 10,000보다 작거나 같은 자연수이다.
 * 
 * 출력
 * 첫째 줄에 N번째 영화 제목에 들어간 수를 출력한다.
 */
#include <iostream>
#include <string>

using namespace std;

int N;

int main(void)
{
	cin >> N;
	string answer;
	int num = 666;

	while (true)
	{
		string title;

		title = to_string(num);
		if (title.find("666") != string::npos)
			N--;
		if (N == 0)
		{
			cout << title << "\n";
			break ;
		}
		num++;
	}
}
