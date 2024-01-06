
#include "regle.h"
#include "base_connaissance.h"
#include "base_fait.h"
#include "moteur_inference.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Main function to interact with every other files in the project
 * @return 0 if everything run properly
 */
int main(){

    int choice; // Variable pour le choix d'action du menu
    BC base_connaissance = create_empty_base(); // Initialisation de la base de connaissance
    BF base_faits = create_empty_fact_base(); // Initialisation de la base de faits


    // Declaration des regles et de la base de connaissance
        // COPY / PASTE the "Rules and Knowledge base" lines here to have pre-written rules


    // Utilisation du menu
    do {
        printf("\n------ Menu ------\n"); // Affichage du menu
        printf("1. Ajouter un fait a la base\n");
        printf("2. Lancer le moteur d'inference\n");
        printf("3. Affichage de la nouvelle base de faits\n");
        printf("4. Quitter\n");
        printf("Que voulez-vous faire : ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: // Ajouter un fait a la base
                {
                    char fact;
                    printf("Quel fait voulez-vous ajouter : ");
                    fact = getchar();
                    base_faits = add_fact_to_tail(base_faits, fact);
                    printf("\nFait ajoute\n");
                }
                break;

            case 2: // Lancer le moteur d'inference
                printf("\nLancement du moteur d'inference\n");
                base_faits = moteur_inference(base_faits, base_connaissance);
                break;

            case 3: // Affichage de la base de fait
                printf("\nAffichage de la base de faits\n");
                print_fact_base(base_faits);
                break;

            case 4:
                printf("Sortie du programme\n");
                break;

            default:
                printf("Choix invalide, veuillez entrer un numero valide\n");

        }

    } while (choice != 4  );


    // Liberer la memoire
    free(base_connaissance);
    free(base_faits);

    return 0;
}