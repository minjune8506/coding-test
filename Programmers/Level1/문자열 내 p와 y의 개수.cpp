#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool solution(string s)
{
    int cntp = 0, cnty = 0;
    
    for (int i = 0 ; i < s.length() ; i++) {
        if (tolower(s[i]) == 'p') {
            cntp++;
        } else if (tolower(s[i]) == 'y') {
            cnty++;
        }
    }
    if (cntp != cnty) {
        return false;
    }
    return true;
}
