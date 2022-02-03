/*
 * 2605 : 줄 세우기
 * 학생들이 한 줄로 줄을 선 후, 첫 번째 학생부터 차례대로 번호를 뽑느다.
 * 첫번째 학생은 무조건 0번 번호를 받아 제일 앞에 줄을 선다. 1
 * 두번째 학생은 0, 1번 둘중 하나의 번호를 뽑고 1번을 뽑으면 앞의 학생 앞으로 가서 줄을 선다. 2 1
 * 이와 같이 뽑은 번호의 위치로 옮기게 된다.
 * 각자 뽑은 번호는 자신이 처음에 선 순서보다는 작은 수이다.
 * 입력 : 첫째줄에는 학생의 수, 둘쨰 줄에는 줄을 선 차례대로 학생들이 뽑은 번호가 주어진다.
 * 학생수는 100이하이고, 번호는 0 또는 자연수이며 학생들이 뽑은 번호 사이에는 빈 칸이 하나씩 있다.
 * 출력 : 학생들이 처음에 줄을 선 순서대로 1번부터 번호를 매길 떄, 첫째 줄에 학생들이 최종적으로 줄을 선
 * 번호로 출력한다. 학생 번호 사이에는 한칸의 공백을 출력한다.
*/

/*
 * 풀이
 * c++ list를 이용해서 이중 연결 리스트를 선언한다.
 * iterator 를 list의 끝을 향하게 한 후, position 위치 만큼 감소시킨다.
 * iterator의 위치에 insert
*/

#include <iostream>
#include <list>

using namespace std;

void print(list<int> &l)
{
	list<int>::iterator it;

	for (it = l.begin() ; it != l.end() ; it++)
		cout << *it << " ";
	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    list<int> order_list;
	list<int>::iterator it;
    int student;

    cin >> student;
    for (int i = 1 ; i <= student ; i++)
    {
		int position;

		cin >> position;
		it = order_list.end();
		for (int j = 0 ; j < position ; j++)
			it--;
		order_list.insert(it, i);
    }
	print(order_list);
}
