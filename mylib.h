#ifndef MYLIB_H
#define MYLIB_H

#define MAX_LEN 12
#define MAX_HEIGHT 10
#define MAX_COMMUNITY_LEN 6
#define MAX_COMMUNITY_HEIGHT 5
#define CARD_NUM 52
#define STARTING_BRANDS 500


typedef struct{
    int rank;
    const char* suit;
    
}Card;


typedef struct{

    char name[1024];
    int brands;

}Player;

enum face_cards{
    JACK = 11,
    QUEEN,
    KING,
    ACE

};

int player_decision();

void raise(int* deposit,Player* player);

void call(int* deposit, Player* player);

int return_brands(Player* player);

void execute_decision(int decision, int* deposit, Player* actor, Player* opponent, int* folded);

void print_deposit(int deposit);

void add_to_deposit(unsigned int num,int* deposit);

void initialize_player(Player* player);

void initialize_cards(Card deck[]);

void shuffle_cards(Card deck[]);

void print_communitycards(Card cards[],int num_cards,int* deposit);

void print_mycards(Card card1, Card card2);


#endif