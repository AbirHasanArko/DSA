#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    bool isValid = true;

    for (char c : s) {
        if (!isalnum(c)) {
            isValid = false;
            break;
        }
    }

    if (isValid) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    
    return 0;
}