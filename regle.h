
#ifndef LO21_REGLE_H
#define LO21_REGLE_H

#include <stdbool.h>

typedef struct premisse{
    char prop;
    struct premisse *next;
}premisse;


typedef struct rule{
    char conclusion;
    premisse *condition;
}rule;

typedef rule* Regle;

Regle create_empty_rule();
Regle add_condition(Regle r);
Regle create_conclusion(Regle r);
bool prop_belong_to_rule(char prop, premisse *p);
Regle clear_premise_prop(char prop, Regle r);
bool is_premise_empty(Regle r);
char access_heap_prop(Regle r);
char access_conclusion(Regle r);

#endif //LO21_REGLE_H
