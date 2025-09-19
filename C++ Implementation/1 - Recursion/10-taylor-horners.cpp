#include <iostream>

using namespace std;

// recursive
double e(int m, int n)
{
    static double s = 1;

    if (n == 0) {
        return s;
    }

    s = 1 + ((double)m / n) * s;

    return e(m, n - 1);
}


int main()
{
    cout << e(4, 15) << endl;
    
    return 0;
}

/*
// iterative
double e(int m, int n)
{
    double s = 1;

    for (; n > 0; n--) {
        s = 1 + ((double)m / n) * s;
    }

    return s;
}
*/