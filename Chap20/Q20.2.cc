#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct {
    int suit;
    int num;
    int idx;
} Card;

Card *create_deck () {
    Card *deck = new Card[52];

    for (int i = 1 ; i <= 4 ; i++) {
        for (int j = 1 ; j <= 13 ; j++) {
            int idx = (i - 1) * 13 + (j - 1);
            deck[idx].suit = i;
            deck[idx].num  = j;
            deck[idx].idx = idx;
        }
    }

    return deck;
}

void print_card (Card crd) {
    switch (crd.suit) {
        case 1:
            printf ("S%-2d ", crd.num);
            break;
        case 2:
            printf ("H%-2d ", crd.num);
            break;
        case 3:
            printf ("D%-2d ", crd.num);
            break;
        case 4:
            printf ("C%-2d ", crd.num);
            break;
        default:
            printf ("??? ");
            break;
    }
    return;
}

void print_card_by_idx (int idx) {
    int suit = idx / 13 + 1;
    int num = idx % 13 + 1;
    Card crd;
    crd.suit = suit;
    crd.num = num;
    print_card (crd);
    return;
}

void print_deck (Card *deck) {
    for (int i = 0 ; i < 52 ; i++) {
        print_card (deck[i]);
        if (i % 13 == 12) {
            printf ("\n");
        }
    }
    return;
}

void fisher_yates_shuffle (Card *deck) {
    for (int i = 51 ; i >= 1 ; i--) {
        int idx = rand () % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[idx];
        deck[idx] = temp;
    }
    return;
}

Card rand_draw (Card *deck) {
    Card ret;
    ret = deck[rand () % 52];
    return ret;
}

int main () {
    srand (time (NULL));

    Card *deck = create_deck ();


    printf ("Shuffle Test\n");
    printf ("----------------------------------------\n");
    printf ("Current deck:\n");
    print_deck (deck);

    printf ("\n");

    fisher_yates_shuffle (deck);

    printf ("Shuffled deck:\n");
    print_deck (deck);

    printf("\n");
    
    printf ("Card Draw Test\n");
    printf ("----------------------------------------\n");

    int counters[52] = {0};

    for (int i = 0 ; i < 5200000 ; i++) {
        Card temp = rand_draw (deck);
        counters[temp.idx] ++;
    }

    for (int i = 0 ; i < 52 ; i++) {
        print_card_by_idx (i);
        printf(": %-10d\n", counters[i]);
    }

    return 0;
}
