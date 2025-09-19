#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "Hello World";

    cout << s << endl;

    cout << sizeof(s) << endl;
    cout << s.length() << endl;
    cout << s.size() << endl;
    
    return 0;
}