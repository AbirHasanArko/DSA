#include <iostream>

using namespace std;

int nCr(int n, int r)
{
    if (r == 0 || r == n) {
        return 1;
    }

    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    cout << nCr(4, 2) << endl;
    
    return 0;
}

/*
int fact(int n)
{
    if (n == 0) {
        return 1;
    }

    return n * fact(n - 1);
}

// formula: factorial-oriented method
int nCr(int n, int r)
{
    int num = fact(n);
    int den = fact(r) * fact(n - r);

    return num / den;
}
*/