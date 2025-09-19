#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void recur_perm(string &s, int index, vector<string> &results)
{
    if (index == s.length()) {
        results.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        swap(s[index], s[i]);
        recur_perm(s, index + 1, results);
        swap(s[index], s[i]);
    }
}

vector<string> permutation(string& s)
{
    vector<string> results;

    recur_perm(s, 0, results);

    sort(results.begin(), results.end());
    return results;
}


int main()
{
    string s = "AABC";

    vector<string> ans = permutation(s);

    for (string st : ans) {
        cout << st << endl;
    }
    
    return 0;
}