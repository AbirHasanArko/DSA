#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            cout << "Not Palindrome" << endl;
            return 0;
        }
    }
    cout << "Palindrome" << endl;
    
    return 0;
}