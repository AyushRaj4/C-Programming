// Name: broker.c
// Purpose: To calculate and display commision taken by 2 brokers in stock trading
//

/* Calculates a broker's commission */
#include <stdio.h>
int main(void) {
    int shares;
    float price_per_share, value, commission, commission2;

    printf("Enter shares and price per share: ");
    scanf("%d%f", &shares, &price_per_share);

    value = shares * price_per_share;

    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;
    if (commission < 39.00f)
        commission = 39.00f;

    if (shares < 2000)
        commission2 = 33 + (3 * shares) / 100;
    else
        commission2 = 33 + (2 * shares) / 100;

    printf("Commission of broker A: $%.2f\n", commission);
    printf("Commission of broker B: $%.2f\n", commission2);

    return 0;
}
