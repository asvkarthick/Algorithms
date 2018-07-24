#include <stdio.h>

/*
    Algorithm:

    Given an integer representing a given amount of change, write a function to compute
    the total number of coins required to make that amount of change.

    Assume American coins (1, 5, 10 and 25 cents)
*/

int makechange(int *coins, int n, int change)
{
    int number_of_coins = 0, accumulated = 0;

    if(change <= 0)
        return 0;

    printf("Coins are: ");
    n--;
    while(change != accumulated)
    {
        if(coins[n] + accumulated <= change)
        {
            accumulated += coins[n];
            number_of_coins++;
            printf("%d ", coins[n]);
        }
        else
        {
            n--;
        }
    }
    printf("\n");

    return number_of_coins;
}

int main(void)
{
    int n, change;
    int coins[] = { 1, 5, 10, 25 };

    n = sizeof(coins) / sizeof(coins[0]);

    printf("Enter value to change: ");
    scanf("%d", &change);
    printf("Number of coins to change %d = %d\n", change, makechange(coins, n, change));

    return 0;
}
