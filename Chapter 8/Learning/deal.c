// Name: deal.c
// Purpose: To deal a given number of cards to the user randomly, no dealt card should be same
// Author: Ayush Raj

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    int num_cards;
    bool deck[NUM_SUITS][NUM_RANKS] = {false};

    char suit_codes[] = {'c', 'd', 'h', 's'};
    char rank_codes[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    srand((unsigned)time(NULL));
    printf("Your hand:");
    while (num_cards) {
        int rand_suit = rand() % NUM_SUITS;
        int rand_rank = rand() % NUM_RANKS;

        if (deck[rand_suit][rand_rank])
            continue;

        deck[rand_suit][rand_rank] = true;
        printf(" %c%c", rank_codes[rand_rank], suit_codes[rand_suit]);
        num_cards--;
    }
    printf("\n");

    return 0;
}
