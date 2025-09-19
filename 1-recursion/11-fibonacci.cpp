#include <iostream>

using namespace std;

int F[10];

// Memoization
int fib(int n)
{
    if (n <= 1) {
        F[n] = n;
        return n;
    } else {
        if (F[n - 2] == -1) {
            F[n - 2] = fib(n - 2);
        }
        if (F[n - 1] == -1) {
            F[n - 1] = fib(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    fill_n(F, 10, -1);

    cout << fib(6) << endl;
    
    return 0;
}

/*
// Recursive
int fib(int n)
{
    if (n <= 1) {
        return n;
    }

    return fib(n - 2) + fib (n - 1);
}

// Iterative
int fib(int n)
{
    int t0 = 0, t1 = 1, s;

    if (n <= 1) {
        return n;
    }

    for (int i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}
*/