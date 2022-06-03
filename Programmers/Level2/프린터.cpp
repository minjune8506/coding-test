#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int> > printer;
    
    for (int i = 0 ; i < priorities.size() ; i++) {
        printer.push(make_pair(priorities[i], i)); // Queue로 이동
    }
    sort(priorities.begin(), priorities.end()); // priority 정렬
    int index = priorities.size() - 1;
    while (!printer.empty()) {
        pair<int, int> front = printer.front();
        if (front.first == priorities[index]) { // 제일 우선순위가 높은 작업인지 확인
            answer++; // 출력 횟수 증가
            index--; // 우선순위 인덱스 감소
            if (front.second == location) { // 우선순위가 제일 높은 작업이 location이랑 같은지
                break ;
            }
        }
        else {
			printer.push(printer.front()); // 큐 회전
		}
        printer.pop();
    }
    return answer;
}
