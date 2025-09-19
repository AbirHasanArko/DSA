// 3 7 4 9 12 6 1 11 2 10 [1...max natural numbers]   (unsorted)

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};

    int length = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];
    for (int i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int H[max + 1] = {0};

    for (int i = 0; i < length; i++) {
        H[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        if (H[i] == 0) {
            cout << i << endl;
        }
    }
    
    return 0;
}