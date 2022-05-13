#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for (int i = 0 ; i < n ; i++) {
        i % 2 ? answer += "박" : answer += "수";
    }
    return answer;
}
