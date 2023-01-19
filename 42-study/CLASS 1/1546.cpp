/**
 * @file 1546.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 평균
 * @date 2023-01-19
 * 
 * 점수 중 최대값 = M
 * 모든 점수를 점수 / M * 100으로 고쳤다.
 * 
 * 위의 방법대로 새로 점수를 계산하고, 평균을 구하라
 * 
 * 과목의 개수 N (< 1000)
 * 현재 성적(0 <= x < 100)
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

int main(void) {
	int N;

	std::cin >> N;
	std::vector<double> grades;
	for (int i = 0; i < N; i++) {
		double grade;
		std::cin >> grade;
		grades.push_back(grade);
	}

	std::sort(grades.begin(), grades.end());
	double maxGrade = *(grades.end() - 1);
	
	double sum = 0;
	for (auto &it : grades) {
		it = it / maxGrade * 100;
		sum += it;
	}

	std::cout << sum / N << std::endl;
}
