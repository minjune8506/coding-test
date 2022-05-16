#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int countDay = 0;
    vector<int> days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 각 Month의 Day수
    vector<string> dayOfTheWeek = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}; // 요일 배열
    for (int i = 0 ; i + 1 < a ; i++) {
        countDay += days[i];
    }
    countDay += (b - 1);
    answer = dayOfTheWeek[(5 + (countDay % 7)) % 7];
    return answer;
}
