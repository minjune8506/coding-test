#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int length = s.length();
    return length & 1 ? s.substr(length / 2, 1) : s.substr(length / 2 - 1, 2);
}
