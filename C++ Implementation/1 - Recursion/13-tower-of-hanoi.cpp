#include <iostream>

using namespace std;

int min_moves = 0;

void TOH(int n, char a, char b, char c)
{
    if ( n > 0) {
        TOH(n - 1, a, c, b);
        cout << "From " << a << " to " << c << endl;
        min_moves++;
        TOH(n - 1, b, a, c);
    }
}

int main()
{
    TOH(3, 'A', 'B', 'C');

    cout << "Minimum Moves: " << min_moves << endl;
    
    return 0;
}