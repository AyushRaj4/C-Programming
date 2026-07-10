// Name: poker_hand.c
// Purpose: To read a hand of 5 cards and classify the hand into one of the categories given in the C book (page 231).
// Author: Ayush Raj

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

void read_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]);
void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS], bool *straight, bool *flush, bool *four, bool *three, int *pairs);
void print_result(bool *straight, bool *flush, bool *four, bool *three, int *pairs);

int main(void) {
    while (1) {
        int num_in_rank[NUM_RANKS] = {0};
        int num_in_suit[NUM_SUITS] = {0};
        bool straight, flush, four, three;
        int pairs; /* can be 0, 1, or 2 */

        read_cards(num_in_rank, num_in_suit);
        analyze_hand(num_in_rank, num_in_suit, &straight, &flush, &four, &three, &pairs);
        print_result(&straight, &flush, &four, &three, &pairs);
    }

    return 0;
}

void read_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]) {
    bool card_exists[NUM_RANKS][NUM_SUITS] = {false};
    int cards_count = 0;
    for (;;) {
        if (cards_count == NUM_CARDS)
            break;

        bool bad_card = false;
        char rank_ch, suit_ch;
        printf("Enter a card: ");
        scanf(" %c", &rank_ch);
        if (rank_ch == '0') {
            printf("Losers always quit!\n");
            exit(0);
        }
        scanf(" %c", &suit_ch);

        int rank = 0, suit = 0;
        if (rank_ch >= '2' && rank_ch <= '9')
            rank = rank_ch - '0' - 2;
        else {
            if (rank_ch == 't' || rank_ch == 'T')
                rank = 8;
            else if (rank_ch == 'j' || rank_ch == 'J')
                rank = 9;
            else if (rank_ch == 'q' || rank_ch == 'Q')
                rank = 10;
            else if (rank_ch == 'k' || rank_ch == 'K')
                rank = 11;
            else if (rank_ch == 'a' || rank_ch == 'A')
                rank = 12;
            else
                bad_card = true;
        }

        if (suit_ch == 'c' || suit_ch == 'C')
            suit = 0;
        else if (suit_ch == 'd' || suit_ch == 'D')
            suit = 1;
        else if (suit_ch == 'h' || suit_ch == 'H')
            suit = 2;
        else if (suit_ch == 's' || suit_ch == 'S')
            suit = 3;
        else
            bad_card = true;

        // this loop prevents user from giving unnecessary inputs, we only need 2 character, if user enters more we will mark the card as bad
        char ch;
        while ((ch = getchar()) != '\n')
            if (ch != ' ')
                bad_card = true;

        if (bad_card) {
            printf("Bad card; ignored.\n");
        } else if (card_exists[rank][suit]) {
            printf("Duplicate card; ignored.\n");
            continue;
        } else {
            card_exists[rank][suit] = true;
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            cards_count++;
        }
    }
}

void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS], bool *straight, bool *flush, bool *four, bool *three, int *pairs) {
    *flush = *straight = *four = *three = false;
    *pairs = 0;

    int consecutive_ranks = 0, same_suit = 0, same_rank = 0;

    for (int i = 0; i < NUM_RANKS; i++) {
        if (num_in_rank[i])
            consecutive_ranks++;
        else if (consecutive_ranks < NUM_CARDS)
            consecutive_ranks = 0;

        if (num_in_rank[i] > same_rank)
            same_rank = num_in_rank[i];

        if (num_in_rank[i] == 2)
            ++*pairs;
    }

    for (int i = 0; i < NUM_SUITS; i++) {
        if (num_in_suit[i] > same_suit)
            same_suit = num_in_suit[i];
    }

    if (consecutive_ranks == NUM_CARDS)
        *straight = true;

    if (same_suit == NUM_CARDS)
        *flush = true;

    if (same_rank == 4)
        *four = true;

    if (same_rank == 3)
        *three = true;
}

void print_result(bool *straight, bool *flush, bool *four, bool *three, int *pairs) {
    if (*straight && *flush) {
        printf("Straight flush\n");
    }

    else if (*four) {
        printf("Four-of-a-kind\n");
    }

    else if (*three && *pairs == 1) {
        printf("Full house\n");
    }

    else if (*flush) {
        printf("Flush\n");
    }

    else if (*straight) {
        printf("Straight\n");
    }

    else if (*three) {
        printf("Three-of-a-kind\n");
    }

    else if (*pairs == 2) {
        printf("Two pairs\n");
    }

    else if (*pairs == 1) {
        printf("Pair\n");
    }

    else {
        printf("High card\n");
    }

    printf("\n");
}
