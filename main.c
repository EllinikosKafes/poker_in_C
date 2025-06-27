#include <stdio.h>
#include <stdbool.h>
#include "mylib.h"

int main(void){

    bool is_active = true;
    Card deck[CARD_NUM];
    char is_ready=0;
    
    printf("- - - -"
    "WELCOME TO NIKITAS' POKER"
    "- - - -\n");

    printf("Are you ready to play?(Y/N)");
    scanf("%c",&is_ready);

    Player player;

    initialize_player(&player);

    printf("Hello %s ! You have %d brands!\n",player.name, player.brands);

    initialize_cards(deck);
    shuffle_cards(deck);

/*  printf("%s %d\n",deck[0].suit, deck[0].rank);
    printf("%s %d\n",deck[1].suit, deck[1].rank);
    printf("%s %d\n",deck[2].suit, deck[2].rank);

    printf("%s %d\n",deck[3].suit, deck[3].rank);
    printf("%s %d\n",deck[4].suit, deck[4].rank);
    printf("%s %d\n",deck[5].suit, deck[5].rank);
 */   
    while (is_active && (is_ready=='Y' || is_ready=='y')){

        Card community_cards[5];
        for(int j=0; j<5; j++){
            community_cards[j]=deck[j];
        }

        print_communitycards(community_cards,5);
        print_mycards(deck[5],deck[6]);

        is_active = false;


    }
    return 0;
}