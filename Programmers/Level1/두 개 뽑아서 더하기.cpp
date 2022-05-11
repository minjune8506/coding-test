#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    // set<int>::iterator iter;
    
    for (int i = 0 ; i < numbers.size() ; i++) {
        for (int j = i + 1 ; j < numbers.size() ; j++) {
            s.insert(numbers[i] + numbers[j]); // 더할 수 있는 모든 경우를 set에 추가
        }
    }
    answer.assign(s.begin(), s.end());
    // for (iter = s.begin() ; iter != s.end() ; iter++) { // set -> vector로 옮긴다.
    //     answer.push_back(*iter);
    // }
    return answer;
}
