#include <iostream>

using namespace std;

// recursive
int fact(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return fact(n - 1) * n;
    }
}

int main()
{
    int a = 5;

    cout << fact(a) << endl;
    
    return 0;
}

/*
// iterative
int fact(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }

    return f;
}
*/