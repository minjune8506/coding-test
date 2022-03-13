/**
 * 5430 : AC
 * 
 * AC는 정수 배열에 연산을 하기 위해 만든 언어이다.
 * 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
 * R : 배열에 있는 수의 순서를 뒤집는 함수
 * D : 첫 번째 수를 버리는 함수. 배열이 비어있는데 D를 사용한 경우 에러 발생
 * 배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하라
 * 
 * 입력
 * 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
 * 각 테스트 케이스의 첫쨰 줄에는 수행할 함수 p가 주어진다.
 * p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
 * 다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 <= n <= 100,000)
 * 다음 줄에는 [x1, ..., xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 <= xi <= 100)
 * 전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.
 * 
 * 출력
 * 각 테스트 케이스에 대해, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다.
 * 만약, 에러가 발생한 경우 error를 출력한다.
 */
#include <iostream>
#include <string>
#include <cctype>
#include <deque>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (int i = 0 ; i < testCase ; i++)
	{
		string cmd;
		int arraySize;
		string arrayContent;
		deque<int> deq;

		// input
		cin >> cmd;
		cin >> arraySize;
		cin >> arrayContent;
		for (int i = 0 ; i < arrayContent.size() ; i++)
		{
			string num = "";
			if (deq.size() == arraySize)
				break ;
			while (isdigit(arrayContent[i]))
			{
				num += arrayContent[i];
				i++;
			}
			if (arrayContent[i] == ',' || arrayContent[i] == ']')
				deq.push_back(stoi(num));
		}

		// operations
		bool rflag = false, error = false;
		for (int i = 0 ; i < cmd.size() ; i++)
		{
			if (cmd[i] == 'R')
				rflag = !rflag;
			else
			{
				if (!deq.size())
				{
					cout << "error" << "\n";
					error = true;
					break ;
				}
				if (rflag)
					deq.pop_back();
				else
					deq.pop_front();
			}
		}

		// print
		if (!error)
		{
			cout << "[";
			while (!deq.empty())
			{
				int temp;

				if (rflag)
					temp = deq.back();
				else
					temp = deq.front();
				cout << temp;
				if (deq.size() != 1)
					cout << ",";
				if (rflag)
					deq.pop_back();
				else
					deq.pop_front();
			}
			cout << "]\n";
		}
	}
}
