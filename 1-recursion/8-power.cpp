#include <iostream>

using namespace std;

// Recursive Efficient
int pow(int m, int n)
{
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return pow(m * m, n / 2);
    } else {
        return m * pow(m * m, (n - 1) / 2);
    }
}

int main()
{
    cout << pow(2, 9) << endl;
    
    return 0;
}

/*
// recursive 
int pow(int m, int n)
{
    if (n == 0) {
        return 1;
    } else {
        return pow(m, n - 1) * m;
    }
}
*/