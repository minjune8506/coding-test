/**
 * @file 9935.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 문자열 폭발
 * @date 2023-04-20
 *
 * 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라진다.
 * 남은 문자열은 합쳐지게 된다.
 *
 * - 문자열이 폭발 문자열을 포함하고 있는 경우 모든 폭발 문자열 폭발
 * - 남은 문자열을 순서대로 붙여 새로운 문자열을 만든다.
 * - 반복
 *
 * 남아있는 문자 없는 경우 FRULA 출력
 *
 * 1 <= 문자열 길이 <= 1,000,000
 * 1 <= 폭발 문자열 <= 36
 * 문자열은 알파벳 대/소문자, 0 ~ 9로 이루어져있다.
 */
#include <iostream>

std::string str;
std::string explosion;

void solve() {
	std::string temp;
	for (int i = 0; i < str.size(); i++) {
		temp += str[i];
		if (temp.length() >= explosion.length()) {
			bool isSame = true;
			int index = temp.length() - 1;
			for (int j = explosion.length() - 1; j >= 0; j--) {
				if (temp[index] != explosion[j]) {
					isSame = false;
					break;
				}
				index--;
			}
			if (isSame) {
				temp.erase(temp.end() - explosion.length(), temp.end());
			}
		}
	}
	if (temp.length()) {
		std::cout << temp << '\n';
		return;
	}
	std::cout << "FRULA" << '\n';
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> str >> explosion;
	solve();
}
