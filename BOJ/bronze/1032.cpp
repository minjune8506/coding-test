/**
 * 1032 : 명령 프롬프트
 * 
 * dir a?b.exe라고 검색하면 파일명의 첫 번째 글자가 a이고, 세번째 글자가 b이고, 확장자가 exe인 것이
 * 모두 나온다. 이때 두번째 문자는 아무거나 나와도 된다.
 * 예를 들어, acb.exe aab.exe apb.exe가 있다.
 * 이 문제는 검색 결과가 먼저 주어졌을 떄, 패턴으로 뭘 쳐야 그 결과가 나오는지 출력하는 문제이다.
 * 패턴에는 알파벳과 "." "?"만 넣을 수 있다. 가능하면 ?을 적게 써야 한다.
 * 
 * 입력
 * 첫째 줄에 파일 이름의 개수 N이 주어진다.
 * 둘쨰 줄부터 N개의 줄에 파일 이름이 주어진다.
 * N은 50보다 작거나 같은 자연수이고, 파일이름의 길이는 모두 같고, 길이는 최대 50이다.
 * 파일이름은 알파벳 소문자와 '.'로만 이루어져 있다.
 * 
 * 출력
 * 첫째 줄에 패턴을 출력한다.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

int main(void)
{	
	vector<string> files;
	string pattern;

	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		string fileName;
		
		cin >> fileName;
		files.push_back(fileName);
	}

	pattern = files[0];
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < files[i].size() ; j++)
		{
			if (pattern[j] == '?')
				continue ;
			if (pattern[j] != files[i][j])
				pattern[j] = '?';
		}
	}
	cout << pattern << "\n";
}
