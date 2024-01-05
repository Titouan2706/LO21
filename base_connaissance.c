
#include "base_connaissance.h"
#include <malloc.h>


/**
 * Function creates an empty knowledge base
 * @return a base
 */
BC create_empty_base(){
    BC base = malloc(sizeof(BC));
    if (base != NULL){
        base->rule = NULL;
        base->next = NULL;
    }
}


/**
 * Function add a rule to the tail of a base
 * @param base the base in which to add the rule
 * @param rule the rule to add
 * @return the modified base
 */
BC add_rule_to_tail(BC base, Regle rule){
    if (base != NULL){
        BC newb = malloc(sizeof(BC));
        newb->next = NULL;
        newb->rule = rule;
        if (base->next != NULL){
            BC temp = base->next;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newb;
        } else {
            base->next = newb;
        }
    }
    return base;
}


/**
 * Function accesses to the first rule of a base
 * @param base to search in
 * @return the first rule of the base
 */
Regle access_to_head_base(BC base){
    return base->rule;
}