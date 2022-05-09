#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long longNum = (long long)num; // long long으로 형변환 오버플로우 방지
    
    while (longNum != 1) {
        if (answer >= 500) // 500회가 넘을시 -1 리턴
            return -1;
        if (longNum % 2 == 0) { // 짝수
            longNum /= 2;
        } else { // 홀수
            longNum = longNum * 3 + 1;
        }
        answer++;
    }
    return answer;
}
