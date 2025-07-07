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

void raise(int* deposit,Player* player){

    int value;
    printf("How much will you raise:");
    do{
        scanf("%d",&value);
    }
    while(value > player->brands);
    
    player->brands-=value;
    add_to_deposit(value,deposit);
}

void call(int* deposit, Player* player){
    
}

int return_brands(Player* player){
    return player->brands;
}

int player_decision(){

    int decision = 0;
    printf("1)Raise\n2)Check\n3)Call\n4)Fold\n");
    scanf("%d",&decision);
    return decision;

}

void execute_decision(int decision, int* deposit, Player* actor, Player* opponent, int* folded) {
    switch (decision) {
        case 1:  // Raise
            printf("%s raised!\n", actor->name);
            int raise_amount;
            printf("How much will you raise, %s? ", actor->name);
            scanf("%d", &raise_amount);
            if (raise_amount > actor->brands) {
                raise_amount = actor->brands;
                printf("You don't have enough brands, so you're going all-in with %d!\n", raise_amount);
            }
            actor->brands -= raise_amount;
            *deposit += raise_amount;
            break;

        case 2:  // Check
            printf("%s checked.\n", actor->name);
            break;

        case 3:  // Call
            printf("%s called!\n", actor->name);
            // For simplicity: match a fixed amount
            int call_amount = 20;
            if (call_amount > actor->brands) {
                call_amount = actor->brands;
                printf("%s is going all-in with %d!\n", actor->name, call_amount);
            }
            actor->brands -= call_amount;
            *deposit += call_amount;
            break;

        case 4:  // Fold
            printf("%s folded!\n", actor->name);
            *folded = 1;
            break;

        default:
            printf("Invalid decision!\n");
            break;
    }
}




void add_to_deposit(unsigned int num,int* deposit){
    
    *deposit+=num;
    
}

void print_deposit(int deposit){
    printf("DEPOSIT IS:%d\n",deposit);
    

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

void print_communitycards(Card cards[], int num_cards, int* deposit) {
    for (int i = 0; i < MAX_COMMUNITY_HEIGHT; i++) {
        for (int c = 0; c < num_cards; c++) {

            if (i == 0 || i == MAX_COMMUNITY_HEIGHT - 1) {
                // Top or bottom border of a card
                for (int j = 0; j < MAX_COMMUNITY_LEN + 2; j++) printf("-");
                
            }
            
            else if (i == 1) {
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
