#include <string>
#include <vector>

using namespace std;

// 에라토스테네스의 체
int solution(int n) {
    int answer = 0;
    vector<bool> primeArray(n + 1, true);
    
    for (int i = 2 ; i * i <= n ; i++) {
        for (int j = i * i ; j <= n ; j += i) {
            primeArray[j] = false;
        }
    }
    for (int i = 2 ; i < n + 1 ; i++) {
        if (primeArray[i] == true) {
            answer++;
        }
    }
    return answer;
}
