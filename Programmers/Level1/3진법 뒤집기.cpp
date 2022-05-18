#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string ternary = "";
    
    while (n != 0) { // 3진법으로 바꾼다.
        ternary = ternary + to_string(n % 3);
        n /= 3;
    }
    for (int i = 0 ; i < ternary.size() ; i++) { // 10진법으로 바꾸기
        answer = answer * 3 + ternary[i] - '0';
    }
    return answer;
}
