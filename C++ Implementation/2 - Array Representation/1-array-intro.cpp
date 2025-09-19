#include <iostream>

using namespace std;

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[5];   // Declaration
    print_array(A, sizeof(A) / sizeof(A[0]));

    int B[5] = {2, 4, 6, 8, 10};    // Declaration & Initialization
    print_array(B, sizeof(B) / sizeof(B[0]));

    int C[5] = {2, 4};
    print_array(C, sizeof(C) / sizeof(C[0]));

    int D[5] = {0};
    print_array(D, sizeof(D) / sizeof(D[0]));

    int E[] = {1,3,5,7,9};
    print_array(E, 5);

    // Accessing Elements
    cout << B[2] << endl;       // using index
    cout << 2[B] << endl;
    cout << *(B + 2) << endl;   // using pointer
    
    return 0;
}