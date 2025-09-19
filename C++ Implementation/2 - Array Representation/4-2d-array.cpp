#include <iostream>
#include <iomanip>

using namespace std;

void fill_array(int A[][4], int r, int c);
void print_array(int A[][4], int r, int c);
void fill_array(int* A[], int r, int c);
void print_array(int* A[], int r, int c);

int main()
{
    // Using 2D array syntax
    // 2D Array
    int A[3][4];

    // demonstration
    fill_array(A, 3, 4);
    print_array(A, 3, 4);


    // Using array of pointers, where each pointer points to an dynamic array
    // Array of pointers
    int *B[3];

    // making each pointer point to an array
    for (int i = 0; i < 3; i++) {// making each pointer point to an array
        B[i] = new int[4];
    }

    // demonstration
    fill_array(B, 3, 4);
    print_array(B, 3, 4);

    // memory deallocation 
    for (int i = 0; i < 3; i++) {
        delete []B[i];
        B[i] = nullptr;
    }


    // Using double pointer, that points to dynamic array of pointers, where each pointer points to an dynamic array
    // Double pointer
    int **C;
    // Double pointer pointing to dynamic array of pointers
    C = new int*[3];

    // making each pointer point to an array
    for (int i = 0; i < 3; i++) {   
        C[i] = new int[4];
    }

    // demonstration
    fill_array(C, 3, 4);
    print_array(C, 3, 4);

    // memory deallocation 
    for (int i = 0; i < 3; i++) {
        delete []C[i];
        C[i] = nullptr;
    }
    delete []C;
    C = nullptr;
    
    return 0;
}

void fill_array(int A[][4], int r, int c)
{
    int val = 1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            A[i][j] = val;
            val++;
        }
    }
}

void print_array(int A[][4], int r, int c)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << setw(4) << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void fill_array(int* A[], int r, int c)
{
    int val = 1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            A[i][j] = val++;
        }
    }
}

void print_array(int* A[], int r, int c)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << setw(4) << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}