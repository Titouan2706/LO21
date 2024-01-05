
#include "regle.h"
#include <stdlib.h>
#include <stdio.h>



/**
 * Function create a new rule that is empty
 * @return a new rule
 */
Regle create_empty_rule() {
    Regle newr = malloc(sizeof(rule));
    newr->conclusion = '\0';
    newr->condition = NULL;
    return newr;
}

/**
 * Function add a condition to the premise of a rule
 * @param r a rule to which the premise will be added
 * @return the rule with the new premise
 */
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


/**
 * Function create the conclusion of a rule
 * @param r the rule to which the conclusion will be added
 * @return the rule with its conclusion
 */
Regle create_conclusion(Regle r){
    if(r!=NULL) {
        char conclu;
        printf("Entrer la conclusion a ajouter");
        scanf("%c", &r->conclusion);
    }
    return r;
}

/**
 * Function check if a given proposition belongs to a rule
 * @param prop a proposition
 * @param p a premise of a certain rule
 * @return true if prop belongs to the rule, false if not
 */
bool prop_belong_to_rule(char prop, premisse *p){
    if (p == NULL) { // Si la prémisse est nulle, donc la proposition n'appartient pas à la règle
        return false; // Proposition n'appartient pas à la prémisse
    }

    if (p->prop == prop) { // Vérifie si la proposition appartient à la prémisse testée
        return true; // Proposition appartient à la prémisse
    }

    return prop_belong_to_rule(prop, p->next); // Rappel de la fonction en passant à la prémisse suivante
}



/**
 * Function delete a given proposition of the premise of a rule
 * @param prop the proposition to delete
 * @param r a rule
 * @return the rule r with the proposition prop deleted
 */
Regle clear_premise_prop(char prop, Regle r){
    premisse *current = r->condition; // Variables nécessaire au parcours de la liste et à sa modifications
    premisse *prev = NULL;

    while (current != NULL) { // Parcours de la prémisse de la règle tant qu'on est pas à la fin
        if (current->prop == prop) { // Vérifie si la proposition  correspond à celle à supprimer
            if (prev != NULL) { // // Modifie la liste pour supprimer la proposition
                prev->next = current->next;
            } else { // Si on se trouve en début de chaine (première proposition, donc prev initialisée à NULL)
                r->condition = current->next;
            }
            free(current); // Supprime la proposition
            break; // Element supprimé donc fin de boucle
        }
        prev = current; // MAJ des pointeurs de parcours de la liste
        current = current->next;
    }
    return r; // Retourne la liste modifié
}



/**
 * Function check if the premise of a rule is empty
 * @param r a rule
 * @return true if premise is empty, false if not
 */
bool is_premise_empty(Regle r){
    if(r->condition == NULL){
        return true;
    }
    return false;
}


/**
 * Function gives the first premise of a rule
 * @param r a rule
 * @return the proposition of the first premise
 */
char access_heap_prop(Regle r){
    return r->condition->prop;
}


/**
 * Function accesses to the conclusion of a rule
 * @param r a rule
 * @return the conclusion of r
 */
char access_conclusion(Regle r){
    return r->conclusion;
}