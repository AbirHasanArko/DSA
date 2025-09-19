// arr1: 1 2 3 4 5 6 8 9 10 11 12   (sorted)
// arr2: 6 7 8 9 10 11 13 14 15 16 17   (sorted)

#include <iostream>

using namespace std;

int main()
{
    // arr1

    int arr1[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};

    int l1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr1_sum = 0;
    for (int  i = 0; i < l1; i++) {
        arr1_sum += arr1[i];
    }

    int s1 = arr1[l1 - 1];
    int arr1_expected_sum = s1 *(s1 + 1) / 2;

    cout << arr1_expected_sum - arr1_sum << endl;

    // arr2

    int arr2[] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};

    int l2 = sizeof(arr2) / sizeof(arr2[0]);

    int diff = arr2[0] - 0;

    for (int i = 0; i < l2; i++) {
        if (arr2[i] - i != diff) {
            cout << i + diff << endl;
            break;
        }
    }
    
    return 0;
}