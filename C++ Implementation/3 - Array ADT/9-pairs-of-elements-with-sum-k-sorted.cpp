// 1 3 4 5 6 8 9 10 12 14 (n sorted elements)
// a + b = k

#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int k = 10;

    int arr[n] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};

    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] == k) {
            cout << arr[i] << ", " << arr[j] << endl;
            i++;
            j--;
        } else if (arr[i] + arr[j] < k) {
            i++;
        } else {
            j--;
        }
    }
    
    return 0;
}