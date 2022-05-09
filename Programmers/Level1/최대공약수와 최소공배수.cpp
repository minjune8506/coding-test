#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = n, b = m;
    int r;
    while (b != 0) { // 유클리드 호제법
        r = a % b;
        a = b;
        b = r;
    }
    answer.push_back(a); // 최대 공약수
    answer.push_back(n * m / a); // 최소 공배수
    return answer;
}
