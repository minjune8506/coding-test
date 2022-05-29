#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10; // *
    int right = 12; // #

    for (int i = 0 ; i < numbers.size() ; i++) {
        if (numbers[i] % 3 == 1) { // 1 4 7
            answer += "L";
            left = numbers[i];
        } else if (numbers[i] % 3 == 0 && numbers[i] != 0) { // 3 6 9
            answer += "R";
            right = numbers[i];
        } else { // 2 5 8 0
            int num = numbers[i] != 0 ? numbers[i] : 11; // 0인경우 11로 변경
            
            int left_w = abs((num - 1) % 3 - (left - 1) % 3); // 왼손 가로
            int left_h = abs((num - 1) / 3 - (left - 1) / 3); // 왼손 세로
            int left_dist = left_h + left_w; // 왼손 거리
            
            int right_w = abs((num - 1) % 3 - (right - 1) % 3); // 오른손 가로
            int right_h = abs((num - 1) / 3 - (right - 1) / 3); // 오른손 세로
            int right_dist = right_h + right_w; // 오른손 거리
            
            if (left_dist < right_dist) {
                answer += "L";
                left = num;
            } else if (left_dist == right_dist) { // 거리가 같은 경우 주로 사용하는 손
                if (hand == "right") {
                    answer += "R";
                    right = num;
                } else {
                    answer += "L";
                    left = num;
                }
            } else {
                answer += "R";
                right = num;
            }
        }
    }
    return answer;
}
