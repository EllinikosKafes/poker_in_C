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

void initialize_player(Player* player);

void initialize_cards(Card deck[]);

void shuffle_cards(Card deck[]);

void print_communitycards(Card cards[],int num_cards);

void print_mycards(Card card1, Card card2);


#endif