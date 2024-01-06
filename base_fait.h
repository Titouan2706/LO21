
#ifndef PROJET_BASE_FAIT_H
#define PROJET_BASE_FAIT_H

typedef struct Base_fait {
    char Fait;
    struct Base_fait *next;
} Base_fait;

typedef Base_fait* BF;

BF create_empty_fact_base();
BF add_fact_to_tail(BF fact, char newf);
char access_to_head_fact(BF fact);

#endif //PROJET_BASE_FAIT_H
