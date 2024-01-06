
#include "base_fait.h"
#include <malloc.h>





/**
 * Function creates an empty fact base
 * @return the new fact base
 */
BF create_empty_fact_base(){

    BF new_f = malloc(sizeof(BF)); // Allocation de la memoire pour la nouvelle base de faits

    if (new_f != NULL){ // Si l'allocation s'est bien deroulee
        new_f->Fait = '\0';
        new_f->next = NULL;
    }

    return new_f; // Retourne la base créée

}


/**
 * Function add a fact to the tail of a base
 * @param fact the base to which add the element
 * @param prop the element to add
 * @return the modified base
 */
BF add_fact_to_tail(BF fact, char prop){

    BF new_f_temp = (BF)malloc(sizeof(struct Base_fait)); // Allocation de memoire pour la creation d'un nouvel élément

    if (new_f_temp != NULL) { // Si pas d'erreur d'allocation de memoire
        new_f_temp->Fait = prop; // Initialisation du nouvel élément
        new_f_temp->next = NULL;

        if (fact->Fait == '\0') {
            return new_f_temp; // Si la base initiale est vide, retourne le nouvel elementE
        } else {
            BF temp = fact;

            while (temp->next != NULL) {
                temp = temp->next; // Parcours la base jusqu'à atteindre le dernier fait
            }

            temp->next = new_f_temp; // Ajoute le nouveau fait à la fin de la base existante
        }
    }

    return fact; // Retourne la base modifiée

}


/**
 * Function gives access to the first fact of a fact base
 * @param fact the fact base to access
 * @return the first fact if the base isn't NULL, \0 else
 */
char access_to_head_fact(BF fact){

    if (fact != NULL) { // Si la base n'est pas vide
        return fact->Fait; // Retourne le fait en tête de la base
    } else {
        return '\0'; // Caractère nul en cas de base vide
    }

}


/**
 * Function checks if a fact belongs to the base
 * @param base_fait the base to check
 * @param fait_verif the fact to check
 * @return true if the fact is already in the base, false if not
 */
bool is_fact_in_base(BF base_fait, char fait_verif){

    BF current = base_fait; // Variable pour le parcours de la base

    while (current != NULL) { // Tant qu'il reste des elements dans la base

        if (current->Fait == fait_verif) { // Fait trouvé
            return true;
        }

        current = current->next; // Iteration suivante
    }

    return false;

}

