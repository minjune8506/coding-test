/**
 * @file 2754.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 학점계산
 * @date 2023-01-17
 * 
 * 성적이 주어졌을때, 평점은 몇점인지 출력하는 프로그램
 * 
 */
#include <iostream>
#include <iomanip>
#include <string>

int main(void) {
	std::string grade;
	std::cin >> grade;

	double gpa;
	if (grade == "A+") {
		gpa = 4.3;
	} else if (grade == "A0") {
		gpa = 4.0;
	} else if (grade == "A-") {
		gpa = 3.7;
	} else if (grade == "B+") {
		gpa = 3.3;
	} else if (grade == "B0") {
		gpa = 3.0;
	} else if (grade == "B-") {
		gpa = 2.7;
	} else if (grade == "C+") {
		gpa = 2.3;
	} else if (grade == "C0") {
		gpa = 2.0;
	} else if (grade == "C-") {
		gpa = 1.7;
	} else if (grade == "D+") {
		gpa = 1.3;
	} else if (grade == "D0") {
		gpa = 1.0;
	} else if (grade == "D-") {
		gpa = 0.7;
	} else if (grade == "F") {
		gpa = 0.0;	
	}
	std::cout << std::fixed << std::setprecision(1) << gpa << std::endl;
}
