#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib.h"

void initialize_player(Player* player){
    
    printf("Write down your name or username:");
    scanf("%s",player->name);
    printf("How many brands would like to start with:");
    scanf("%d",&player->brands);

}

void initialize_cards(Card deck[]) {
    const char* suits[] = {"♥", "♦", "♠", "♣"};  // or even just {'H', 'D', 'S', 'C'}
    int index = 0;

    for (int s = 0; s < 4; s++) {
        for (int r = 2; r <= 14; r++) {
            deck[index].suit = suits[s];  // one character
            deck[index].rank = r;
            index++;
        }
    }
}


void shuffle_cards(Card deck[]){
    srand(time(NULL));
    for(int i=0; i<CARD_NUM; i++){

        int j = rand() % CARD_NUM;
        Card temp = deck[i];
        deck[i]=deck[j];
        deck[j]=temp;
    }

}

void print_communitycards(Card cards[], int num_cards) {
    for (int i = 0; i < MAX_COMMUNITY_HEIGHT; i++) {
        for (int c = 0; c < num_cards; c++) {

            if (i == 0 || i == MAX_COMMUNITY_HEIGHT - 1) {
                // Top or bottom border of a card
                for (int j = 0; j < MAX_COMMUNITY_LEN + 2; j++) printf("-");

            } else if (i == 1) {
                // Card value row

                switch (cards[c].rank)
                {
                case JACK:
                    printf("|%-*c%s|", MAX_COMMUNITY_LEN-1, 'J',cards[c].suit);
                    break;
                case QUEEN:
                    printf("|%-*c%s|", MAX_COMMUNITY_LEN-1, 'Q',cards[c].suit);
                    break;
                case KING:
                    printf("|%-*c%s|", MAX_COMMUNITY_LEN-1, 'K',cards[c].suit);
                    break;
                case ACE:
                    printf("|%-*c%s|", MAX_COMMUNITY_LEN-1, 'A',cards[c].suit);
                    break;
                default:
                    printf("|%-*d%s|", MAX_COMMUNITY_LEN-1, cards[c].rank, cards[c].suit);
                    break;
                }
            
            
                

            } else {
                // Empty space inside the card
                printf("|");
                for (int j = 0; j < MAX_COMMUNITY_LEN; j++) printf(" ");
                printf("|");
            }

            // Space between cards
            printf("  ");
        }
        printf("\n");
    }

    printf("\n\n");
}


void print_mycards(Card card1,Card card2) {
    Card my_cards[]={card1,card2};
    for (int i = 0; i < MAX_HEIGHT; i++) {
        
        // Print top or bottom border for both cards

        if (i == 0 || i == MAX_HEIGHT - 1) {
            for (int j = 0; j < MAX_LEN + 2; j++) printf("-");
            printf("  ");
            for (int j = 0; j < MAX_LEN + 2; j++) printf("-");
            printf("\n");
        }

        // Print number line
        else if (i == 1) {
            for(int k = 0; k<2; k++){
                switch (my_cards[k].rank)
                {
                case JACK:
                    printf("|%-*c%s|  ", MAX_LEN-1, 'J',my_cards[k].suit);
                    break;
                case QUEEN:
                    printf("|%-*c%s|  ", MAX_LEN-1, 'Q',my_cards[k].suit);
                    break;
                case KING:
                    printf("|%-*c%s|  ", MAX_LEN-1, 'K',my_cards[k].suit);
                    break;
                case ACE:
                    printf("|%-*c%s|  ", MAX_LEN-1, 'A',my_cards[k].suit);
                    break;
                default:
                    printf("|%-*d%s|  ", MAX_LEN-1, my_cards[k].rank, my_cards[k].suit);
                    break;
                }
            }
            printf("\n");
        }

        // Empty middle lines
        else {
            printf("|");
            for (int j = 0; j < MAX_LEN; j++) printf(" ");
            printf("|  ");
            printf("|");
            for (int j = 0; j < MAX_LEN; j++) printf(" ");
            printf("|\n");
        }
    }
}
