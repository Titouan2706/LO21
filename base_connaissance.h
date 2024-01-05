
#ifndef PROJET_BASE_CONNAISSANCE_H
#define PROJET_BASE_CONNAISSANCE_H

#include "regle.h"

typedef struct BC{
    Regle rule;
    struct BC *next;
}BC;

BC create_empty_base();
BC add_rule_to_tail(BC base, Regle rule);
Regle access_to_head_base(BC base);

#endif //PROJET_BASE_CONNAISSANCE_H
