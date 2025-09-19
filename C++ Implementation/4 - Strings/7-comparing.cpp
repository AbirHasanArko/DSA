#include <iostream>

using namespace std;

int main()
{
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    if (s1 == s2) {
        cout << "Same Same" << endl;
    } else {
        cout << "But Different" << endl;
    }
    
    return 0;
}