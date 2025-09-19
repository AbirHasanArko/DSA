// 6 3 8 10 16 7 5 2 9 14
// a + b = k

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 10;
    int k = 10;
    int arr[n] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};

    int max = *max_element(arr, arr + n);

    int H[max] = {0};

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k && H[k - arr[i]] != 0) {
            cout << arr[i] << ", " << k - arr[i] << endl;
        }
        H[arr[i]]++;
    }
    
    return 0;
}


/*
int main()
{
    int n = 10;
    int k = 10;
    int arr[n] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                cout << arr[i] << ", " << arr[j] << endl;
            }
        }
    }
    
    return 0;
}
*/