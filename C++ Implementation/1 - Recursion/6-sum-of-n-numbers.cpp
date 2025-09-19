#include <iostream>

using namespace std;

// recursive
int sum(int n)
{
    if (n == 0) {
        return 0;
    } else {
        return sum(n - 1) + n;
    }
}

int main()
{
    int a = 5;

    cout << sum(a) << endl;
    
    return 0;
}

/*
// iterative
int sum(int n)
{
    int s = 0;
    for (int i = 0; i <= n; i++) {
        s += i;
    }
    return s;
}

// formula
int sum(int n)
{
    return n*(n + 1) / 2;
}
*/