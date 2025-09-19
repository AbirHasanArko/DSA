#include <iostream>

using namespace std;

int main()
{
    // static array
    int A[5] = {2, 4, 6, 8, 10};

    for (int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // dynamic array
    int *P;
    P = new int[5];

    P[0] = 1; P[1] = 3; P[2] = 5; P[3] = 7; P[4] = 9;

    for (int i = 0; i < 5; i++) {
        cout << P[i] << " ";
    }
    cout << endl;

    delete []P;
    
    return 0;
}