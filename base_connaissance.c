
#include "base_connaissance.h"
#include <malloc.h>





/**
 * Function creates an empty knowledge base
 * @return a base
 */
BC create_empty_base(){

    BC base = malloc(sizeof(BC)); // Allocation de la memoire pour la base de connaissance

    if (base != NULL){ // Si l'allocation n'a pas echouée
        base->rule = NULL; // Initialisation à NULL de la base de connaissance
        base->next = NULL;
    }

    return base; // Retourne la base de connaissance créée

}



/**
 * Function add a rule to the tail of a base
 * @param base the base in which to add the rule
 * @param rule the rule to add
 * @return the modified base
 */
BC add_rule_to_tail(BC base, Regle rule){

    BC new_b = malloc(sizeof(Base_Connaissance)); // Allocation de la memoire pour une nouvelle base
    new_b->next = NULL; // Ajout en queue
    new_b->rule = rule; // Regle a ajouter

    if (base == NULL) { // Si base vide, retourner directement le nouvel element
        return new_b;
    }

    BC temp = base; // Base n'est pas vide, variable temporaire pour l'ajout en queue

    while (temp->next != NULL){ // Atteindre la dernière regle
        temp = temp->next;
    }

    temp->next = new_b; // Ajout en queue
    return base;

}



/**
 * Function accesses to the first rule of a base
 * @param base to search in
 * @return the first rule of the base
 */
Regle access_to_head_base(BC base){

    if (base != NULL) { // Si la base existe
        return base->rule;
    } else {
        return NULL;
    }

}