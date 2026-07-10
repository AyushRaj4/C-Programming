// Name: poker_hand.c
// Purpose: To read a hand of 5 cards and classify the hand into one of the categories given in the C book (page 231).
// Author: Ayush Raj

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight = true, flush = true, four, three;
int pairs; /* can be 0, 1, or 2 */

void read_cards(int poker_hand[NUM_CARDS][2]);
void analyze_hand(int poker_hand[NUM_CARDS][2]);
void print_result(void);
void selection_sort(int poker_hand[NUM_CARDS][2]);

int main(void) {
    while (1) {
        int poker_hand[NUM_CARDS][2] = {0};

        read_cards(poker_hand);
        selection_sort(poker_hand);
        analyze_hand(poker_hand);
        print_result();

        for (int i = 0; i < NUM_CARDS; i++)
            printf("%d%d ", poker_hand[i][0], poker_hand[i][1]);
        printf("\n");
    }

    return 0;
}

void read_cards(int poker_hand[NUM_CARDS][2]) {
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    for (int i = 0; i < NUM_CARDS; i++) {
        while (1) {
            bool bad_card = false;
            char rank_ch, suit_ch;
            int rank = 0, suit = 0;

            printf("Enter a card: ");
            scanf(" %c", &rank_ch);
            rank_ch = tolower(rank_ch);

            if (rank_ch == '0') {
                printf("\nLosers always quit!\n");
                exit(0);
            }

            scanf("%c", &suit_ch);
            suit_ch = tolower(suit_ch);

            if (rank_ch >= '2' && rank_ch <= '9') {
                rank = rank_ch - '0' - 2;
            } else {
                switch (rank_ch) {
                    case 't':
                        rank = 8;
                        break;
                    case 'j':
                        rank = 9;
                        break;
                    case 'q':
                        rank = 10;
                        break;
                    case 'k':
                        rank = 11;
                        break;
                    case 'a':
                        rank = 12;
                        break;
                        break;
                    default:
                        bad_card = true;
                        break;
                }
            }

            switch (suit_ch) {
                case 'c':
                    suit = 0;
                    break;
                case 'd':
                    suit = 1;
                    break;
                case 'h':
                    suit = 2;
                    break;
                case 's':
                    suit = 3;
                    break;
                default:
                    bad_card = true;
                    break;
            }

            char ch;
            while ((ch = getchar()) != '\n') {
                if (ch != ' ') {
                    bad_card = true;
                }
            }

            if (bad_card) {
                printf("Bad card; ignored.\n");
                continue;
            } else {
                int j;
                for (j = 0; j < i; j++) {
                    if (rank == poker_hand[j][0] && suit == poker_hand[j][1]) {
                        printf("Duplicate card; ignored.\n");
                        break;
                    }
                }
                if (j == i) {
                    poker_hand[i][0] = rank;
                    poker_hand[i][1] = suit;
                    break;
                }
            }
        }
    }
}

void analyze_hand(int poker_hand[NUM_CARDS][2]) {
    for (int i = 0; i < NUM_CARDS - 1; i++) {
        if (poker_hand[i][0] == poker_hand[i + 1][0]) {
            pairs++;
        }

        if (poker_hand[i][0] != poker_hand[i + 1][0] - 1) {
            straight = false;
        }

        if (poker_hand[i][1] != poker_hand[i + 1][1]) {
            flush = false;
        }
    }

    if (poker_hand[0][0] == poker_hand[3][0] || poker_hand[1][0] == poker_hand[4][0]) {
        four = true;
        pairs = 0;
    } else if (poker_hand[0][0] == poker_hand[2][0] || poker_hand[1][0] == poker_hand[3][0] || poker_hand[2][0] == poker_hand[4][0]) {
        three = true;
        if (pairs >= 3) {
            pairs = 1;
        } else if (pairs == 2) {
            pairs = 0;
        }
    }
}

void print_result(void) {
    if (straight && flush) {
        printf("Straight flush\n");
    }

    else if (four) {
        printf("Four-of-a-kind\n");
    }

    else if (three && pairs == 1) {
        printf("Full house\n");
    }

    else if (flush) {
        printf("Flush\n");
    }

    else if (straight) {
        printf("Straight\n");
    }

    else if (three) {
        printf("Three-of-a-kind\n");
    }

    else if (pairs == 2) {
        printf("Two pairs\n");
    }

    else if (pairs == 1) {
        printf("Pair\n");
    }

    else {
        printf("High card\n");
    }

    printf("\n");
}

void selection_sort(int poker_hand[NUM_CARDS][2]) {
    int i, j, min_idx, temp_rank, temp_suit;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < NUM_CARDS - 1; i++) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < NUM_CARDS; j++) {
            // Compare ranks (stored in column 0)
            if (poker_hand[j][0] < poker_hand[min_idx][0]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        // Swap Rank
        temp_rank = poker_hand[min_idx][0];
        poker_hand[min_idx][0] = poker_hand[i][0];
        poker_hand[i][0] = temp_rank;

        // Swap Suit (Very important: the suit must stay with its rank!)
        temp_suit = poker_hand[min_idx][1];
        poker_hand[min_idx][1] = poker_hand[i][1];
        poker_hand[i][1] = temp_suit;
    }
}
