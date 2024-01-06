
#ifndef LO21_BASE_CONNAISSANCE_H
#define LO21_BASE_CONNAISSANCE_H




#include "regle.h"


typedef struct Base_Connaissance{
    Regle rule;
    struct Base_Connaissance *next;
}Base_Connaissance;


typedef Base_Connaissance* BC;


BC create_empty_base();

BC add_rule_to_tail(BC base, Regle rule);

Regle access_to_head_base(BC base);




#endif //LO21_BASE_CONNAISSANCE_H
