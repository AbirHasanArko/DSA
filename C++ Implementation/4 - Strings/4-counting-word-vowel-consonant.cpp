#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int word = 0, vowel = 0, consonant = 0;
    bool inWord = false;

    for (char c : s) {
        if (isalpha(c)) {
            char l = tolower(c);
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') {
                vowel++;
            } else {
                consonant++;
            }

            if (!inWord) {
                inWord = true;
                word++;
            }
        } else {
            inWord = false;
        }
    }

    cout << "Word: " << word << endl;
    cout << "Vowel: " << vowel << endl;
    cout << "Consonant: " << consonant << endl;

    return 0;
}