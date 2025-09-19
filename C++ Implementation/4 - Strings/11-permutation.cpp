#include <iostream>
#include <array>
#include <string>

using namespace std;

void permutation(const string& s, int k)
{
    static array<int, 10> A = {0};
    static string Res(10, '\0');

    if (k == s.length()) {
        cout << Res.substr(0, k) << endl;
    } else {
        for (int i = 0; i < s.length(); i++) {
            if (A[i] == 0) {
                Res[k] = s[i];
                A[i] = 1;
                permutation(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    string s = "ABC";

    permutation (s, 0);
    
    return 0;
}