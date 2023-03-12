/**
 * @file 17219.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 비밀번호 찾기
 * @date 2023-03-12
 *
 * 메모장에 사이트 주소와 비밀번호를 저장한다.
 * 메모장에서 비밀번호를 찾는 프로그램
 *
 * 주소의 수 1 <= N <= 100,000
 * 비밀번호를 찾으려는 사이트 주소 수 1 <= M <= 100,000
 *
 * 사이트 주소는 알파벳 - . 으로 이루어져있고 중복 x
 * 비밀번호는 알파벳 대문자
 */
#include <iostream>
#include <map>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	std::map<std::string, std::string> passwords;

	for (int i = 0; i < N; i++) {
		std::string url;
		std::string password;

		std::cin >> url >> password;
		passwords.insert(std::make_pair(url, password));
	}

	for (int i = 0; i < M; i++) {
		std::string url;

		std::cin >> url;
		std::cout << passwords.find(url)->second << '\n';
	}
}
