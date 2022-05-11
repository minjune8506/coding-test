#include <string>
#include <vector>

using namespace std;

// 0이 들어오는 경우는 n이 자연수이기 때문에 고려하지 않아도 되지만, 반례로 좋은 예인것 같다.
vector<int> solution(long long n) {
    vector<int> answer;
    while (n != 0) {
        answer.push_back(n % 10);
        n /= 10;
    }
    return answer;
}
