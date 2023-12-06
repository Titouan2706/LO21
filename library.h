#ifndef LO21_LIBRARY_H
#define LO21_LIBRARY_H

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



#endif //LO21_LIBRARY_H
