
#include "base_fait.h"
#include <malloc.h>


/**
 * Function creates an empty fact abse
 * @return the new fact base
 */
BF create_empty_fact_base(){
    BF newf = malloc(sizeof(BF));
    if (newf != NULL){
        newf->Fait = '\0';
        newf->next = NULL;
    }
    return newf;
}


/**
 *
 * @param fact
 * @return
 */
BF add_fact_to_tail(BF fact, char newf){
    BF newf_temp = (BF)malloc(sizeof(struct Base_fait)); // Creation d'un nouvel élément + allocation mémoire
    if (newf_temp != NULL) { // Si pas d'erreur d'allocation de mémoire
        newf_temp->Fait = newf; // Initialisation du nouvel élément
        newf_temp->next = NULL;

        if (fact == NULL) {
            return newf_temp; // Si la base initiale est vide, la nouvelle base devient la base modifiée
        } else {
            BF temp = fact;
            while (temp->next != NULL) {
                temp = temp->next; // Parcourt la base jusqu'à atteindre le dernier fait
            }
            temp->next = newf_temp; // Ajoute le nouveau fait à la fin de la base existante
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
    if (fact != NULL) {
        return fact->Fait; // Retourne le fait en tête de la base
    } else {
        return '\0'; // Caractère nul en cas de base vide
    }
}