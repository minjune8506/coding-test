#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> numbers;
    
    while (n != 0) {
        numbers.push_back(n % 10);
        n /= 10;
    }
    sort(numbers.begin(), numbers.end(), greater<int>());
    for (int i = 0 ; i < numbers.size() ; i++) {
        answer = answer * 10 + numbers[i];
    }
    return answer;
}
