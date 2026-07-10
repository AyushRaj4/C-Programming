// Name: useful_functions.c
// Purpose: To understand and experiment with time, srand and rand functions
// Author: Ayush Raj

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    // the time function
    printf("Years since January 1, 1970: %ld\n", time(NULL) / 3600 / 24 / 365);

    time_t seconds = time(NULL); // direct initialization
    printf("No. of seconds passed since January 1, 1970: %ld\n", seconds);

    time(&seconds); // updating an already created variable with current time by passing the address of the variable
    printf("No. of seconds passed since January 1, 1970: %ld\n", seconds);
    printf("\n");

    // srand and rand functions
    // The srand() function (Seed Random) initializes the random number generator used by rand(), basically the srand function uses the seed to generate the 1st random number between 0 and RAND_MAX.
    // by default seed is 1 if we don't use srand function
    // rand function generates a random number bw 0 and RAND_MAX based on the seed, it does not generate random numbers on its own everytime it's called because it uses a pre-determined formula based on seed. If seed is same it will generate a sequence of numbers which will always be same for the seed. To generate truly random numbers the seed need to change everytime. For more info, see notes.txt

    srand(5);
    int rand_num = rand(); // everytime the same number will be generated because we are calling rand for one time only, there is a fixed sequence of numbers for a given seed
    // subsequently calling rand() more times will generate the rest of the numbers from the sequence
    printf("Sequence of numbers when seed is 5: %d %d %d\n", rand_num, rand(), rand());

    // next 10 numbers from sequence where seed = 5
    printf("Next 10 numbers from the sequence when seed is 5: ");
    for (int i = 1; i <= 10; i++)
        printf("%d ", rand());
    printf("\n\n");

    // we can use rand() to generate numbers bw a given range
    srand(1);
    // to generate nos. bw 1 and 6, seed = 1
    rand_num = (rand() % 6) + 1; // formula: (rand() % max - min + 1) + min
    printf("No. bw 1 and 6: %d\n", rand_num);

    // using loop to generate random nos. 20 times bw 1 and 10 with seed = 1
    // notice that the same sequence of numbers will be generated, changing seed will change the sequence
    printf("Random numbers bw 1 and 10 (seed = 1, 20 times): ");
    for (int i = 1; i <= 20; i++) {
        rand_num = (rand() % 10) + 1;
        printf("%d ", rand_num);
    }
    printf("\n");

    // using time to generate truly random numbers
    // we will use the time function to change the seed each time which will change the sequence eacht ime and thus we get truly random numbers

    // generating random numbers bw 0 and 100 (including both) using time, srand and rand functions
    srand((unsigned)time(NULL));
    rand_num = (rand() % 101) + 0;
    printf("Random number bw 0 and 100 (including both): %d\n", rand_num);

    return 0;
}
