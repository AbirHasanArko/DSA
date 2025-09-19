#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int H = 0, x = 0;

    for (char &c : s) {
        c = tolower(c);
        x = 1;
        x = x << (c - 'a');

        if ((x & H) > 0) {
            cout << c << " is duplicate\n";
        } else {
            H = H | x;
        }
    }
    
    return 0;
}