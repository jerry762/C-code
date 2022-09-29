#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CARDS_NUM 52
#define FACES_NUM 13
#define SUITS_NUM 4
#define FUNCTION_NUM 5
#define RANK_NUM 7
#define POKER_HAND 5
#define HANDS_OF_CARDS CARDS_NUM / POKER_HAND

typedef struct Card
{
    char suit[10];
    char face[10];
} Card;

typedef struct Deck
{
    Card cards[CARDS_NUM];
} Deck;

void shuffle(Deck *deck);
void deal(Deck *deck, Card hands_of_cards[HANDS_OF_CARDS][POKER_HAND]);
void swap_cards(Card *card1, Card *card2);

//* Five function to judge hand types.

//* judge pair or two pairs.
int func_one(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM]);

//* judge three of a kind or full house.
int func_two(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM]);

//* judge four of a kind.
int func_three(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM]);

//* judge flush.
int func_four(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM]);

//* judge straight.
int func_five(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM]);

int main(void)
{
    const char *faces[FACES_NUM] = {"Ace", "Two", "Three", "Four",
                                    "Five", "Six", "Seven", "Eight",
                                    "Nine", "Ten", "Jack", "Queen",
                                    "King"};

    const char *suits[SUITS_NUM] = {"Club", "Diamond", "Heart", "Spade"};

    const char *rank[RANK_NUM] = {"A pair", "Two pair", "Three of a kind",
                                  "Full house", "Four of a kind", "Straight", "Flush"};

    Deck deck;
    Card hands_of_cards[HANDS_OF_CARDS][POKER_HAND];

    int (*check_hand_type[FUNCTION_NUM])(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM]) = {func_one, func_two, func_three, func_four, func_five};

    for (size_t i = 0; i < SUITS_NUM; i++)
    {
        for (size_t j = 0; j < FACES_NUM; j++)
        {
            strcpy(deck.cards[FACES_NUM * i + j].suit, suits[i]);
            strcpy(deck.cards[FACES_NUM * i + j].face, faces[j]);
        }
    }

    shuffle(&deck);
    deal(&deck, hands_of_cards);

    // for (size_t i = 0; i < CARDS_NUM; i++)
    // {
    //     printf("%20s %20s\n", deck.cards[i].suit, deck.cards[i].face);
    // }

    // for (size_t i = 0; i < HANDS_OF_CARDS; i++)
    // {
    //     for (size_t j = 0; j < POKER_HAND; j++)
    //     {
    //         printf("%-10s %-10s", hands_of_cards[i][j].suit, hands_of_cards[i][j].face);
    //     }
    //     printf("\n\n");
    // }

    for (size_t i = 0; i < HANDS_OF_CARDS; i++)
    {
        for (size_t j = 0; j < POKER_HAND; j++)
        {
            printf("(%s, %s) ", hands_of_cards[i][j].suit, hands_of_cards[i][j].face);
        }
        printf("\n");
        for (int j = FUNCTION_NUM - 1; j >= 0; j--)
        {
            int type = check_hand_type[j](hands_of_cards[i], faces);

            if (type != 0)
            {
                printf("%s", rank[type - 1]);
                break;
            }
        }
        printf("\n\n");
    }

    return 0;
}

void shuffle(Deck *deck)
{
    const size_t shuffle_times = 5000;

    srand(time(NULL));

    for (size_t i = 0; i < shuffle_times; i++)
    {
        int seed1 = rand() % CARDS_NUM;
        int seed2 = rand() % CARDS_NUM;

        swap_cards(&deck->cards[seed1], &deck->cards[seed2]);
    }
}

void swap_cards(Card *card1, Card *card2)
{
    Card temp_card = *card1;
    *card1 = *card2;
    *card2 = temp_card;
}

void deal(Deck *deck, Card hands_of_cards[HANDS_OF_CARDS][POKER_HAND])
{
    for (size_t i = 0; i < HANDS_OF_CARDS; i++)
    {
        for (size_t j = 0; j < POKER_HAND; j++)
        {
            strcpy(hands_of_cards[i][j].suit, deck->cards[POKER_HAND * i + j].suit);
            strcpy(hands_of_cards[i][j].face, deck->cards[POKER_HAND * i + j].face);
        }
    }
}

int func_one(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM])
{
    int counter[FACES_NUM] = {0};
    int rank = 0;

    for (size_t i = 0; i < FACES_NUM; i++)
    {
        for (size_t j = 0; j < POKER_HAND; j++)
        {
            if (strcmp(faces[i], hand_of_cards[j].face) == 0)
            {
                counter[i]++;
            }
        }
    }

    for (size_t i = 0; i < FACES_NUM; i++)
    {
        if (counter[i] == 2)
        {
            printf("Pair's face = %s\n", faces[i]);
            rank++;
        }
    }

    return rank;
}

int func_two(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM])
{
    int counter[FACES_NUM] = {0};
    int rank = 0;

    for (size_t i = 0; i < FACES_NUM; i++)
    {
        for (size_t j = 0; j < POKER_HAND; j++)
        {
            if (strcmp(faces[i], hand_of_cards[j].face) == 0)
            {
                counter[i]++;
            }
        }
    }

    for (size_t i = 0; i < FACES_NUM; i++)
    {
        if (counter[i] == 3)
        {
            printf("Three of a kind's face = %s\n", faces[i]);
            rank = 3;
            for (size_t j = 0; j < FACES_NUM; j++)
            {
                if (counter[j] == 2)
                {
                    printf("Pair's face = %s\n", faces[j]);
                    rank++;
                    break;
                }
            }
            break;
        }
    }

    return rank;
}

int func_three(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM])
{
    int counter[FACES_NUM] = {0};
    int rank = 0;

    for (size_t i = 0; i < FACES_NUM; i++)
    {
        for (size_t j = 0; j < POKER_HAND; j++)
        {
            if (strcmp(faces[i], hand_of_cards[j].face) == 0)
            {
                counter[i]++;
            }
        }
    }

    for (size_t i = 0; i < FACES_NUM; i++)
    {
        if (counter[i] == 4)
        {
            printf("Four of a kind's face = %s\n", faces[i]);
            rank = 5;
            break;
        }
    }

    return rank;
}

int func_four(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM])
{
    int counter[FACES_NUM] = {0};
    int rank = 0;

    for (size_t i = 0; i < FACES_NUM; i++)
    {
        for (size_t j = 0; j < POKER_HAND; j++)
        {
            if (strcmp(faces[i], hand_of_cards[j].face) == 0)
            {
                counter[i]++;
            }
        }
    }

    for (size_t i = 0; i < 9; i++)
    {
        if (counter[i + 0] == 1 &&
            counter[i + 1] == 1 &&
            counter[i + 2] == 1 &&
            counter[i + 3] == 1 &&
            counter[i + 4] == 1)
        {
            printf("Straight's face = %s\n", faces[i]);
            rank = 6;
            break;
        }
    }

    if (counter[9] == 1 &&
        counter[10] == 1 &&
        counter[11] == 1 &&
        counter[12] == 1 &&
        counter[0] == 1)
    {
        printf("Straight's face = %s\n", faces[9]);
        rank = 6;
    }

    return rank;
}

int func_five(const Card hand_of_cards[POKER_HAND], const char *faces[FACES_NUM])
{
    int rank = 7;

    for (size_t i = 1; i < POKER_HAND; i++)
    {
        if (strcmp(hand_of_cards[0].suit, hand_of_cards[i].suit) != 0)
        {
            rank = 0;
            break;
        }
    }

    if (rank == 7)
        printf("Flush's suit = %s\n", hand_of_cards[0].suit);

    return rank;
}
