#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

void recur_perm(string &s, int index, vector<string> &results)
{
    if (index == s.length()) {
        results.push_back(s);
        return;
    }

    unordered_set<char> used;    

    for (int i = index; i < s.length(); i++) {
        if (used.count(s[i])) {
            continue;
        }

        used.insert(s[i]);

        swap(s[index], s[i]);
        recur_perm(s, index + 1, results);
        swap(s[index], s[i]);
    }
}

vector<string> permutation(string& s)
{
    vector<string> results;

    recur_perm(s, 0, results);

    return results;
}


int main()
{
    string s = "AAB";

    vector<string> ans = permutation(s);

    for (string st : ans) {
        cout << st << endl;
    }
    
    return 0;
}