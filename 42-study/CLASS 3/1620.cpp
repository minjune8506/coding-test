/**
 * @file 1620.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 나는야 포켓몬 마스터 이다솜
 * @date 2023-02-19
 *
 * 포켓몬의 이름을 보면 포켓몬의 번호를 말하고
 * 포켓몬의 번호를 보면 포켓몬의 이름을 말하라.
 *
 * 포켓몬의 개수 N 맞춰야 하는 문제의 개수 M(1 <= N, M <= 100,000)
 * 포켓몬의 이름은 모두 영어, 이름은 최대 20 최소 2글자
 *
 * 이름을 key, 번호를 value로 hash map을 만들어 빠르게 검색할 수 있도록 함
 * -> 이름으로 들어온 경우는 상관없지만 번호로 들어오면 어떻게 찾아야 하나?
 * -> map을 두개로 만들면 어떨까? (시간초과) 말이안됨 -> 입출력 최적화? (성공)
 */
#include <cctype>
#include <iostream>
#include <map>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::map<std::string, int> pocketmonDic1;
	std::map<int, std::string> pocketmonDic2;

	int N, M;

	std::cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		std::string pocketmon;

		std::cin >> pocketmon;
		pocketmonDic1.insert(std::make_pair(pocketmon, i));
		pocketmonDic2.insert(std::make_pair(i, pocketmon));
	}

	for (int i = 0; i < M; i++) {
		std::string quiz;

		std::cin >> quiz;
		if (isdigit(quiz.at(0))) {
			auto found = pocketmonDic2.find(std::stoi(quiz));
			std::cout << found->second << '\n';
		} else {
			auto found = pocketmonDic1.find(quiz);
			std::cout << found->second << '\n';
		}
	}
	std::cout << std::endl;
}
