#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    int H[26] = {0};

    for (char &c : s) {
        H[tolower(c) - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (H[i] > 1) {
            cout << (char)('a' + i) << " repeated " << H[i] << " times\n";
        }
    }
    
    return 0;
}