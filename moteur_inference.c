
#include "moteur_inference.h"
#include "stdio.h"





/**
 * Function checks if all the premise of a rule are satisfied by the fact base
 * @param rule the rule in which to check the premise
 * @param base_fait the fact base
 * @return true if all premise are satisfied, false if not
 */
bool are_rule_premises_satisfied(Regle rule, BF base_fait) {

    premisse* current_premise = rule->condition; // Variable de parcours de la regle

    while (current_premise != NULL) { // Parcours de toutes les premisses de la regle
        char prop = current_premise->prop;

        if (!is_fact_in_base(base_fait, prop)) { // Teste si les premisses sont satisfaites ou non
            return false;  // Toutes les premisses ne sont pas satisfaites
        }

        current_premise = current_premise->next;  // Iteration suivante
    }

    return true;  // Toutes les premisses sont satisfaites

}


/**
 * Function is the main function for the inference motor between a fact base and a knowledge base
 * @param base_fait a fact base
 * @param base_connaissance a knowledge base
 * @return a fact base with initials facts and some other fact deduced from the knowledge base
 */
BF moteur_inference(BF base_fait, BC base_connaissance){

    if (base_fait->Fait == '\0' || base_connaissance->rule == NULL) { // Si l'une des deux bases est vide
        printf("\n Erreur de traitement\n");
        return base_fait;
    }

    bool newFactsAdded = true;  // Variable booléenne pour verifier si la base de fait est modifiée

    while (newFactsAdded) {

        newFactsAdded = false;  // On reset la variable booléenne
        BC current_rule = base_connaissance; // Variable pour iteration dans la base de connaissance
        while (current_rule != NULL) { // Tant qu'il reste des regles dans la base de connaissance

            Regle rule = current_rule->rule;

            if (!is_premise_empty(rule) && are_rule_premises_satisfied(rule, base_fait)) { // Si toutes les premisses d'une regle sont satisfaites

                char conclusion = access_conclusion(rule); // Recuperation de la conclusion pour l'ajout en base de fait

                if (!is_fact_in_base(base_fait, conclusion)) { // Si la conclusion n'est pas deja dans la base de fait
                    base_fait = add_fact_to_tail(base_fait, conclusion);
                    newFactsAdded = true;  // Actualisation de la variable booléenne car modification de la base de fait
                }

            }

            current_rule = current_rule->next;  // Prochaine iteration

        }
    }
    printf("\nL'execution du moteur d'inference s'est terminee sans probleme\n");
    return base_fait;  // Retourne la base de fait modifiée

}