#include <iostream>

using namespace std;

// int x = 0;

int fun(int n)
{
    static int x = 0;
    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    int a = 5;

    cout << fun(a) << endl;
    
    return 0;
}

/*
#include <iostream>

using namespace std;

// int x = 0;

int fun(int n)
{
    if (n > 0) {
        return fun(n - 1) + n;
    }
    return 0;
}

int main()
{
    int a = 5;

    cout << fun(a) << endl;
    
    return 0;
}
*/