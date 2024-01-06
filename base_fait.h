
#ifndef PROJET_BASE_FAIT_H
#define PROJET_BASE_FAIT_H




#include <stdbool.h>


typedef struct Base_fait {
    char Fait;
    struct Base_fait *next;
} Base_fait;


typedef Base_fait* BF;


BF create_empty_fact_base();

BF add_fact_to_tail(BF fact, char prop);

char access_to_head_fact(BF fact);

bool is_fact_in_base(BF base_fait, char fait_verif);

void print_fact_base(BF base_fait);




#endif //PROJET_BASE_FAIT_H
