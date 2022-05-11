#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// arr의 원래 내용을 건드리지 않고 최솟값을 제거할 수 있는 방법은?
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() <= 1) {
        answer.push_back(-1);
    } else {
        int min = 0;
        for (int i = 0 ; i < arr.size() ; i++) {
            if (arr[min] > arr[i]) {
                min = i; // arr배열의 최소원소의 위치를 찾는다.
            }
        }
        for (int i = 0 ; i < arr.size() ; i++) {
            if (i == min)
                continue ;
            answer.push_back(arr[i]); // answer 배열에 옮기기
        }
    }
    return answer;
}
