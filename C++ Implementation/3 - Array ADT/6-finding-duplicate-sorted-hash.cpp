// 3 6 8 8 10 12 15 15 15 19

#include <iostream>

using namespace std;

int main()
{
    int n = 10;

    int arr[n] = {3, 6, 8, 8, 10, 12, 15,15, 15, 19};

    int max = arr[n - 1];

    int H[max] = {0};

    for (int i = 0; i < n; i++) {
        H[arr[i]]++;
    }

    // finding duplicates
    for (int i = 0; i < max; i++) {
        if (H[i] > 1) {
            cout << i << endl;
        }
    }

    // counting duplicates
    for (int i = 0; i < max; i++) {
        if (H[i] > 1) {
            cout << i << " appears " << H[i] << " times" << endl;
        }
    }
    
    return 0;
}