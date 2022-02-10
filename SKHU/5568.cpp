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

/*
 * 풀이
 * kCn x
 * 중복인 숫자는 어떻게 처리해야 할지?
 * 
 * ex) 1 2 12 1
 * 4 C 2 ->
 * 4!
 * 2! * (4 - 2)! => 6
 * 
 * 4 P 2 ->
 * 4!
 * (4 - 2)! -> 12
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n,k;
vector<string> card;
set<string> cardSet;

void solve()
 {
	string temp;

	for (int i = 0 ; i < n ; i++)
	{
		temp.clear();
		temp.append(card[i]);
		for (int j = i + 1 ; j < i + k ; j++) // k - 1개 선택 
			temp.append(card[j]);
		cout << "temp : " << temp << "\n";
		cardSet.insert(temp);
	}
 }

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
	{
        string s;
        cin >> s;
        card.push_back(s);
    }
	solve();
    cout << cardSet.size() << '\n';
}
