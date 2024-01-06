
#include "regle.h"
#include <stdio.h>
#include <malloc.h>





/**
 * Function create a new rule that is empty
 * @return a new rule
 */
Regle create_empty_rule() {

    Regle new_r = malloc(sizeof(rule)); // Allocation de memoire pour la nouvelle regle
    new_r->conclusion = '\0';
    new_r->condition = NULL;
    return new_r;

}


/**
 * Function add a condition to the premise of a rule
 * @param r a rule to which the premise will be added
 * @param prop the proposition to add
 * @return the rule with the new premise
 */
Regle add_condition(Regle r, char prop){

    if (r!=NULL) { // Si regle non vide
        premisse *new_p = malloc(sizeof(premisse)); // Allocation de la memoire pour la nouvelle premisse
        new_p->next = NULL; // Ajout en queue
        new_p->prop = prop;

        if (r->condition != NULL) { // Si deja des premisses
            premisse *tmp = r->condition;

            while (tmp->next != NULL) { // Parcours de la regle jusqu'a derniere premisse
                tmp = tmp->next; // Iteration
            }

            tmp->next = new_p;

        } else { // Si pas encore de premisses
            r->condition = new_p;
        }

    }

    return r; // Retourne la regle modifiée

}


/**
 * Function create the conclusion of a rule
 * @param r the rule to which the conclusion will be added
 * @param ccl the conclusion of the rule
 * @return the rule with its conclusion
 */
Regle create_conclusion(Regle r, char ccl){

    if(r!=NULL) { // Si la regle n'est pas nulle
        r->conclusion = ccl;
    }

    return r;

}


/**
 * Function to check if a given proposition belongs to a rule in a recursive way
 * @param prop the proposition to check
 * @param condition the current premise condition
 * @return true if prop belongs to the rule, false if not
 */
bool prop_belong_to_rule_recursive(char prop, premisse* condition) {

    if (condition == NULL) { // Cas basique : il n'y a pas / plus de conditions
        return false;
    }

    if (condition->prop == prop) { // Si la proposition correspond a la premisse actuelle
        return true;
    }

    return prop_belong_to_rule_recursive(prop, condition->next); // Cas recursif : verifie le reste des conditions

}


/**
 * Function check if a given proposition belongs to a rule
 * @param prop the proposition to check
 * @param r a rule
 * @return true if prop belongs to the rule, false if not
 */
bool prop_belong_to_rule(char prop, Regle r) {

    if (r == NULL) { // Si la regle est nulle
        return false;
    }

    return prop_belong_to_rule_recursive(prop, r->condition); // Appel recursif de la fonction

}


/**
 * Function delete a given proposition of the premise of a rule
 * @param prop the proposition to delete
 * @param r a rule
 * @return the rule r with the proposition prop deleted
 */
Regle clear_premise_prop(char prop, Regle r){

    if (r == NULL || r->condition == NULL) { // Si la regle est vide ou si la premisse est vide
        return r;
    }

    premisse *current = r->condition; // Variables concessionaire au parcours de la liste et à sa modifications
    premisse *prev = NULL;

    while (current != NULL) { // Parcours de la prémisse de la regle tant qu'on est pas à la fin

        if (current->prop == prop) { // Vérifie si la proposition  correspond à celle à supprimer

            if (prev != NULL) { // // Modifie la liste pour supprimer la proposition
                prev->next = current->next;
            } else { // Si on se trouve en debut de chaine (premiere proposition, donc prev initialisée à NULL)
                r->condition = current->next;
            }

            free(current); // Supprime la proposition
            break; // Element supprimé donc fin de boucle

        }

        prev = current; // MAJ des pointeurs de parcours de la liste
        current = current->next;
    }

    if (r->condition == NULL && prev != NULL) { // Si element supprimé est le dernier de la liste
        prev->next = NULL;
    }

    return r; // Retourne la liste modifiée

}


/**
 * Function check if the premise of a rule is empty
 * @param r a rule
 * @return true if premise is empty, false if not
 */
bool is_premise_empty(Regle r){

    if(r->condition->prop == '\0' && r->condition->next == NULL){ // Si la regle est vide (premisse)

        return true;
    }

    return false; // Si la regle n'est pas vide

}


/**
 * Function gives the first premise of a rule
 * @param r a rule
 * @return the proposition of the first premise
 */
char access_heap_prop(Regle r){

    if (r != NULL && r->condition != NULL) { // Si la regle n'est pas nulle
        return r->condition->prop;
    }

    return '\0'; // Si la regle est vide

}


/**
 * Function accesses to the conclusion of a rule
 * @param r a rule
 * @return the conclusion of r
 */
char access_conclusion(Regle r){

    if (r != NULL) { // Si la regle n'est pas nulle
        return r->conclusion;
    }

    return '\0'; // Si la regle est vide

}