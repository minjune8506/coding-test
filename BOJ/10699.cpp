/**
 * @file 10699.cpp
 * @author Minjune (minjune8506@gmail.com)
 * @brief 오늘 날짜
 * @date 2023-01-16
 * 
 * 서울의 오늘 날짜를 출력하는 프로그램을 작성하시오.
 */

#include <iostream>
#include <iomanip>
#include <ctime>

int main(void) {
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	std::cout << 1900 + timeinfo->tm_year << "-"
			<< std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1 << "-"
			<< timeinfo->tm_mday << std::endl;
}
