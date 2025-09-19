#include <iostream>

using namespace std;

int main()
{
    int *P = new int[3]{1, 3, 5};

    for (int i = 0; i < 3; i++) {
        cout << P[i] << " ";
    }
    cout << endl;
    
    int *Q = new int[5];
    copy(P, P + 3, Q);

    delete []P;
    P = Q;
    Q = NULL;

    P[3] = 7; P[4] = 9;

    for (int i = 0; i < 5; i++) {
        cout << P[i] << " ";
    }
    cout << endl;
    
    return 0;
}