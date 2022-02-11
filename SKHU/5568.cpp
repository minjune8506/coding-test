/*
 * 5568 : 카드놓기
 *
 * 카드 n(4 <= n <= 10)장을 바닥에 나란히 놓고 놀고있다.
 * 각 카드에는 1이상 99이하의 정수가 적혀있다.
 * 이 카드 중에서 k(2 <= k <=4)장을 선택하고, 가로로 나란히 정수를 만들기로 했다.
 * 상근이가 만들 수 있는 정수는 모두 몇가지일까?
 * 
 * ex) 카드 5장 (1, 2, 3, 13, 21)
 * 3장을 선택해서 정수를 만드려고 한다.
 * 2, 1, 13 -> 2113 을 만들 수 있다.
 * 21, 1, 3 -> 2113을 만들 수 있다. 이렇게 한 정수를 만드는 조합이 여러가지 일 수 있다.
 * 
 * n장의 카드에 적힌 숫자가 주어졌을 때, 그 중 k개를 선택해서 만들 수 있는 정수의 개수를 구하는 프로그램
 * 
 * 입력
 * 1 : n
 * 2 : k
 * 3 ~ : 카드에 적혀 있는 수
 * 
 * 출력
 * 만들 수 있는 정수의 개수
*/

/**
 * 재귀를 이용한 완전탐색 알고리즘
 * 순서가 상관이 있는 경우에 해당된다.
 * 
 * selectCount = 0으로 시작하며 하나씩 카드를 고를때마다 1씩 증가시켜 재귀로 반복한다.
 * 고른 카드를 문자열에 이어 붙혀서 다음 재귀 함수로 넘긴다.
 * selectCount 가 k 일경우 set에 문자열을 추가 후 재귀를 탈출하게 된다.
 * 반복되는 문자의 경우 set이므로 중복이 제거된다.
 * 마지막에 visiteed[i] = false를 해주는 이유는 2번째 카드를 선택했을때
 * 첫번째 카드를 다시 선택할 수 있기 때문이다.
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int n,k;
set<string> cardSet;
bool visited[10];

void brute_force(vector<string> card, int selectCount, string temp)
{
	if (selectCount == k)
	{
		cardSet.insert(temp);
		return ;
	}
	for (int i = 0 ; i < card.size() ; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			brute_force(card, selectCount + 1, temp + card[i]);
			visited[i] = false;
		}
	}
}

int main()
{
	vector<string> card;
	string temp;

	// input
    cin >> n >> k;
    for (int i = 0; i < n; i++)
	{
		cin >> temp;
		card.push_back(temp);
	}
	
	// 완전 탐색
	brute_force(card, 0, "");

	// cardSet 내용 출력
	// set<string>::iterator iter;
	// for (iter = cardSet.begin() ; iter != cardSet.end() ; iter++)
		// cout << *iter << " ";
	// cout << "\n";
	
	// output
    cout << cardSet.size() << "\n";
}
