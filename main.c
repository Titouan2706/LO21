
#include "regle.h"
#include "base_connaissance.h"
#include <stdio.h>


int main(){
/*    Regle R = create_empty_rule();
    if(is_premise_empty(R)){
        printf("Premisse vide\n");
    } else{
        printf("Premisse pas vide\n");
    }
    R = add_condition(R);
    printf("cond add\n");
    R = add_condition(R);
    printf("cond add\n");
    R = add_condition(R);
    printf("cond add\n");
    R = create_conclusion(R);
    printf("ccl add\n");
    if(prop_belong_to_rule('A', R->condition)){
        printf("A appartient aux conditions\n");
    } else{
        printf("A n'appartient pas aux conditions\n");
    }
    R = clear_premise_prop('A', R);
    printf("Head: %c\n", access_heap_prop(R));
    printf("CCL: %c\n", access_conclusion(R));
    */
    BC base = create_empty_base();
    Regle R = create_empty_rule();
    if(is_premise_empty(R)){
        printf("Premisse vide\n");
    } else{
        printf("Premisse pas vide\n");
    }
    R = add_condition(R);
    printf("cond add\n");
    R = create_conclusion(R);
    printf("ccl add\n");
    base = add_rule_to_tail(base, R);
    if (base != NULL){
        printf("base non nulle\n");
    }

    Regle r = create_empty_rule();
    r = access_to_head_base(base);
    if(r == NULL){
        printf("Base vide\n");
    } else {
        printf("Base pas vide\n");
    }
    return 0;
}