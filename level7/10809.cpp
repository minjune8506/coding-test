#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cin >> str;
    for(int i = 0; i < alphabet.length(); i++)
        cout << (int)str.find(alphabet[i]) << " ";
	
    return 0;
}
