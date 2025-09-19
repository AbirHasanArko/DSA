// 5 8 3 9 6 2 10 7 -1 4

#include <iostream>

using namespace std;

int main()
{
    int n = 10;

    int arr[n] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};

    int min = arr[0], max = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    
    return 0;
}