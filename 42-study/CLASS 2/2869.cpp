/**
 * @file 2869.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 달팽이는 올라가고 싶다
 * @date 2023-02-04
 *
 * 달팽이는 높이가 V미터인 나무 막대를 올라간다.
 * 낮에 A미터를 올라가고, 밤에 잠을 자는 동안 B미터 미끄러진다.
 * 정상에 올라간 후에는 미끄러지지 않는다.
 * 나무 막대를 모두 올라가려면 며칠이 걸리는지 구해라
 *
 * 1 <= B < A <= V <= 1,000,000,000
 *
 * - 정상인지 계속 확인하면서 올라가고 미끄러지면 해결될 것 같다.
 * 2 1 5 case
 *
 * 2 -> 1
 * 3 -> 2
 * 4 -> 3
 * 5 (4일)
 *
 * - 단순 반복문으로 해결할 시 시간초과..
 * - 수학적으로 공식을 세워서 해결해야 할 것 같다.
 * - 달팽이가 하루에 올라가는 양 (A - B) 미터
 * - 마지막에 A미터만큼 올라가면 더 이상 올라갈 필요가 없다.
 * - V - A를 A - B로 나눈 후 + 1을 해주면 정답
 * - V - A가 A - B보다 작은 경우 올라가야 하므로 나머지가 있을 때 예외처리 필요
 * (해결)
 */

#include <iostream>

int main(void) {
	int A, B, V;

	std::cin >> A >> B >> V;
	int temp = (V - A) % (A - B);
	int answer = (V - A) / (A - B) + 1;
	std::cout << (temp > 0 ? answer + 1 : answer) << std::endl;
}
