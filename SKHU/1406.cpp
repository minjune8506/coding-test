/*
* 1406 : 에디터
* 한줄로 된 간단한 에디터를 구현하려고 한다.
* 영어 소문자만을 기록할 수 있는 편집기, 최대 600,000글자까지 입력 가능
* 커서 : 문장의 맨앞, 맨뒤, 중간의 임의의 곳에 위치할 수 있따.
* 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는곳은 L + 1가지 경우가 있다.
* L : 커서를 왼쪽으로 한 칸 옮김(문장의 맨앞이면 무시)
* D : 커서를 오른쪽으로 한 칸 옮김(문장의 맨뒤이면 무시)
* B : 커서 왼쪽에 있는 문자를 삭제 (맨 앞이면 무시) 실제 커서의 오른쪽에 있던 문잔느 그대로
* P $ : $라는 문자를 커서 왼쪽에 추가
* 입력
* 초기에 편집기에 입력되어 있는 문자열이 주어진다 (길이 : N, 소문자로만 이루어져 있음, 길이 <= 100,000)
* 입력할 명령어의 개수를 나타내느 정수 M ( 1 <= M <= 500,000)
* M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어짐
* 출력
* 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열 출력
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

void moveCursorLeft(list<char> &l, list<char>::iterator &cursor)
{
	if (cursor != l.begin())
		cursor--;
}

void moveCursorRight(list<char> &l, list<char>::iterator &cursor)
{
	if (cursor != l.end())
		cursor++;
}

void eraseNode(list<char> &l, list<char>::iterator &cursor)
{
	if (cursor != l.begin())
	{
		moveCursorLeft(l, cursor);
		cursor = l.erase(cursor);
	}
}

void insertNode(list<char> &l, list<char>::iterator &cursor)
{
	char ch;

	cin >> ch;
	l.insert(cursor, ch);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<char> l;
	list<char>::iterator cursor;
	string str;
	int M;

	cin >> str;
	cin >> M;
	for (int i = 0 ; i < str.size() ; i++)
		l.push_back(str[i]);
	cursor = l.end();
	for (int i = 0 ; i < M ; i++)
	{
		cin >> str;

		if (str[0] == 'L')
			moveCursorLeft(l, cursor);
		else if (str[0] == 'D')
			moveCursorRight(l, cursor);
		else if (str[0] == 'B')
			eraseNode(l, cursor);
		else if (str[0] == 'P')
			insertNode(l, cursor);
	}
	for (cursor = l.begin() ; cursor != l.end() ; cursor++)
		cout << *cursor;
	cout << "\n";
}
