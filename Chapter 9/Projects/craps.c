// Name: craps.c
// Purpose: To simulate the game of craps, read Q8.
// Author: Ayush Raj

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
    // srand must be called once and time() return value must be converted to unsigned int becuase srand expects unsigned int
    srand((unsigned)time(NULL));
    printf("Let's play the game of craps!\n\n");

    int wins = 0, losses = 0;
    char ch;

    while (1) {
        if (play_game()) {
            wins++;
            printf("You win!\n");
        }

        else {
            losses++;
            printf("You lose!\n");
        }

        printf("\nPlay again? ");
        scanf(" %c", &ch);
        printf("\n");

        if (ch != 'Y' && ch != 'y') {
            break;
        }
    }

    printf("Wins: %d  Losses: %d\n", wins, losses);
    if (losses > wins)
        printf("You fucking loser!\n");
    else
        printf("You fucking cheater!\n");

    return 0;
}

int roll_dice(void) {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

bool play_game(void) {
    int roll = roll_dice();
    int point = roll;
    printf("You rolled: %d\n", roll);

    if (roll == 7 || roll == 11)
        return true;
    if (roll == 2 || roll == 3 || roll == 12)
        return false;

    printf("Your point is: %d\n", roll);

    while (1) {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);

        if (roll == point)
            return true;
        if (roll == 7)
            return false;
    }
}
