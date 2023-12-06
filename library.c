#include "library.h"
#include <stdlib.h>
#include <stdio.h>


Regle create_empty_rule() {
    Regle newr = malloc(sizeof(rule));
    newr->conclusion = '\0';
    newr->condition = NULL;
    return newr;
}

Regle add_condition(Regle r){
    if (r!=NULL) {
        char prop;
        printf("Entrer une proposition à ajouter");
        scanf("%c", &prop);
        premisse *newp = malloc(sizeof(premisse));
        newp->next = NULL;
        newp->prop = prop;
        if (r->condition != NULL) {
            premisse *tmp = r->condition;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newp;
        } else {
            r->condition = newp;
        }
    }
    return r;
}

Regle create_conclusion(Regle r){
    if(r!=NULL) {
        char conclu;
        printf("Entrer la conclusion a ajouter");
        scanf("%c", &r->conclusion);

    }
}


