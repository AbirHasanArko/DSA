// 8 3 6 4 6 5 6 8 2 7

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 10;
    int arr[n] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};

    int max = *max_element(arr, arr + n);
    int H[max + 1] = {0};

    for (int i = 0; i < n; i++) {
        H[arr[i]]++;
    }

    for (int i = 0; i <= max; i++) {
        if (H[i] > 1) {
            cout << i << " appears " << H[i] << " times\n";
        }
    }
    
    return 0;
}


/*
int main()
{
    int n = 10;
    int arr[n] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};

    for (int i = 0; i < n - 1; i++) {
        int count = 1;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j] && arr[j] != -1) {
                count++;
                arr[j] = -1;
            }
        }

        if (count > 1) {
            cout << arr[i] << " appears " << count << " times\n";
        }
    }
    
    return 0;
}
*/