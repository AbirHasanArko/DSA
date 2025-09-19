#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "Verbose";
    string s2 = "Observe";

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 == s2) {
        cout << "Anagram\n";
    } else {
        cout << "Not Anagram\n";
    }
    
    return 0;
}