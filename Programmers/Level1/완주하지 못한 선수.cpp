#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    
    for (auto it : participant) {
        m[it]++;
    }
    for (auto it : completion) {
        m[it]--;
    }
    for (auto it : m) {
        if (it.second >= 1) {
            return (it.first);
        }
    }
}
