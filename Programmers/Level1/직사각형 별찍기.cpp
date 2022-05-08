// 중첩 반복문으로 해결시 O(n^2)
// 문자열을 이용하여 풀이시 O(2n) -> 더 효율적으로 풀이 가능하다.
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int a;
    int b;
    
    cin >> a >> b;

    // for (int i = 0 ; i < b ; i++) {
    //     for (int j = 0 ; j < a ; j++) {
    //         cout << '*';
    //     }
    //     cout << '\n';
    // }

    string str;
    char star = '*';
    
    for (int i = 0 ; i < a ; i++) {
        str += star;
    }
    for (int i = 0 ; i < b ; i++) {
        cout << str << '\n';
    }

    return 0;
}
