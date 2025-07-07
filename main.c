#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "mylib.h"


int main(void){


    unsigned char small_blind=10;
    unsigned char big_blind=20;
    bool is_active = true;
    Card deck[CARD_NUM];
    char is_ready=0;
    
    printf("- - - -"
    "WELCOME TO NIKITAS' POKER"
    "- - - -\n");

    printf("Are you ready to play?(Y/N)");
    scanf("%c",&is_ready);

    Player player;
    Player opponent;
    

    initialize_player(&player);
    opponent.brands= player.brands;
    strcpy(opponent.name,"John Doe");

    
    printf("Hello %s ! You have %d brands!\nYOU ARE VERSUS %s with %d brands\n",player.name, player.brands,opponent.name,opponent.brands);
    
    

/*  printf("%s %d\n",deck[0].suit, deck[0].rank);
    printf("%s %d\n",deck[1].suit, deck[1].rank);
    printf("%s %d\n",deck[2].suit, deck[2].rank);

    printf("%s %d\n",deck[3].suit, deck[3].rank);
    printf("%s %d\n",deck[4].suit, deck[4].rank);
    printf("%s %d\n",deck[5].suit, deck[5].rank);
 */   
    while (is_active && (is_ready=='Y' || is_ready=='y')){

        Card community_cards[5];
        Card player_cards[2];
        Card opponent_cards[2];
        int deposit = 0;
        int round=2;

        initialize_cards(deck);
        shuffle_cards(deck);

        
        // Deal cards
        player_cards[0] = deck[5];
        player_cards[1] = deck[6];
        opponent_cards[0] = deck[7];
        opponent_cards[1] = deck[8];

        // Deal community cards
        for (int j = 0; j < 5; j++) {
            community_cards[j] = deck[j];
        }
        
        add_to_deposit(small_blind, &deposit);
        add_to_deposit(big_blind, &deposit);
        
        
        while(round<=5){
             
            
            int player_bets[]={0,0};
            char next='N';
            print_communitycards(community_cards,round,&deposit);
            print_deposit(deposit);
            print_mycards(deck[5],deck[6]);
            
            int last_raise = 0;
            int folded = 0;
            int decision = player_decision();
            sleep(3);
            execute_decision(decision, &deposit, &player, &opponent, &folded);

            if (folded) {
                printf("%s wins the round by default!\n", opponent.name);
                opponent.brands += deposit;
                break;
            }

            int opp_decision = (rand() % 3) + 2; // 2, 3, 4
            execute_decision(opp_decision, &deposit, &opponent, &player, &folded);

            if (folded) {
                printf("%s wins the round by default!\n", player.name);
                player.brands += deposit;
                break;
            }

            
            printf("You have %d brands left\n",return_brands(&player));
            printf("The opponent has %d brands left\n",return_brands(&opponent));
            if (player_bets[0]==player_bets[1]){
                round++;
            }
        }
        is_active = true;


    }
    return 0;
}