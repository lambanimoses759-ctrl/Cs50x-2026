#include <stdio.h>
#include <limits.h>
#include <math.h>

static double get_change_amount(void)
{
    double amount;

    for (;;)
    {
        printf("Change owed in rands: ");

        if (scanf("%lf", &amount) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
            printf("Invalid input: enter a numeric amount.\n");
            continue;
        }

        if (!isfinite(amount) || amount < 0)
        {
            printf("Invalid amount: enter a finite, non-negative value.\n");
            continue;
        }

        if (amount > (double)INT_MAX / 100.0)
        {
            printf("Invalid amount: value is too large.\n");
            continue;
        }

        return amount;
    }
}

int main(void)
{
    const double amount = get_change_amount();
    const int total_cents = (int)round(amount * 100.0);
    int remaining = total_cents;

    const int coins_available[] = {500, 200, 100, 50, 20, 10, 5};
    const int num_coins = (int)(sizeof(coins_available) / sizeof(coins_available[0]));
    int coins_used = 0;

    for (int i = 0; i < num_coins; i++)
    {
        while (remaining >= coins_available[i])
        {
            remaining -= coins_available[i];
            coins_used++;
        }
    }

    if (remaining > 0)
    {
        printf("Note: %dc cannot be given as change (South Africa has no 1c/2c coins).\n", remaining);
    }

    printf("------------------------\n");
    printf("Amount entered: R%.2f\n", amount);
    printf("Minimum coins needed: %d\n", coins_used);
    printf("------------------------\n");

    return 0;
}
