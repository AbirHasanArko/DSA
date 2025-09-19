#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str = "AAB";

    sort(str.begin(), str.end());

    do {
        cout << str << '\n';
    } while (next_permutation(str.begin(), str.end()));

    return 0;
}


#include <iostream>
#include <string>
#include <algorithm>

// Custom implementation of next_permutation
bool my_next_permutation(std::string &s) {
    int n = s.length();

    // Step 1: Find the largest index i such that s[i] < s[i+1]
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }

    // If no such i exists, it's the last permutation
    if (i < 0) {
        return false;
    }

    // Step 2: Find the largest index j > i such that s[j] > s[i]
    int j = n - 1;
    while (s[j] <= s[i]) {
        j--;
    }

    // Step 3: Swap s[i] and s[j]
    std::swap(s[i], s[j]);

    // Step 4: Reverse the subarray from i+1 to end
    std::reverse(s.begin() + i + 1, s.end());

    return true;
}

int main() {
    std::string str = "aabc";

    std::sort(str.begin(), str.end()); // Start with the smallest permutation

    do {
        std::cout << str << '\n';
    } while (my_next_permutation(str));

    return 0;
}

