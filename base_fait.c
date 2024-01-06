// TOUTES LES FONCTIONS SONT TESTEE ET FONCTIONNENT

#include "base_fait.h"
#include <malloc.h>
#include <stdio.h>

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
BF add_fact_to_tail(BF fact){
    char newf;
    printf("Entrer un fait a ajouter"); // Acquisition du nouveau fait
    scanf(" %c", &newf);
    BF newf_temp = (BF)malloc(sizeof(struct Base_fait)); // Creation d'un nouvel élément + allocation mémoire
    if (newf_temp != NULL) { // Si pas d'erreur d'allocation de mémoire
        newf_temp->Fait = newf; // Initialisation du nouvel élément
        newf_temp->next = NULL;
        if (fact->Fait == '\0') {
            return newf_temp; // Si la base initiale est vide, retourne le nouvel elementE
        } else {
            BF temp = fact;
            while (temp->next != NULL) {
                temp = temp->next; // Parcours la base jusqu'à atteindre le dernier fait
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


/**
 * Function checks if a fact belongs to the base
 * @param base_fait the base to check
 * @param fait_verif the fact to check
 * @return true if the fact is already in the base, false if not
 */
bool is_fact_in_base(BF base_fait, char fait_verif){
    BF current = base_fait;
    while (current != NULL) {
        if (current->Fait == fait_verif) {
            return true;
        }
        current = current->next;
    }
    return false;
}

