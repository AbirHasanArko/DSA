#include <iostream>
#include <climits>

using namespace std;

int coins[] = {1, 2, 3};

int coin_change(int amount)
{
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return INT_MAX;
    }

    int min_coins = INT_MAX;

    for (int coin : coins) {
        int result = coin_change(amount - coin);
        if (result != INT_MAX) {
            min_coins = min(min_coins, result + 1);
        }
    }

    return min_coins;
}

int main()
{
    cout << coin_change(5) << endl;
    
    return 0;
}