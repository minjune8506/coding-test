#include <string>
#include <vector>

using namespace std;


int solution(vector<int> numbers) {
    int answer = 0;
	bool visited[10];

    for (int i = 0 ; i < numbers.size() ; i++) {
        visited[numbers[i]] = true;
    }
    for (int i = 0 ; i < 10 ; i++) {
        if (visited[i] == false) {
            answer += i;
        }
    }
    return answer;
}

// int solution(vector<int> numbers) {
// 	int answer = 45;
// 	for (int i = 0 ; i < numbers.size() ; i++) {
// 		answer -= numbers[i];
// 	}
// 	return answer;
// }
