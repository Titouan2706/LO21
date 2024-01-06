
#ifndef PROJET_MOTEUR_INFERENCE_H
#define PROJET_MOTEUR_INFERENCE_H




#include "base_connaissance.h"
#include "base_fait.h"


BF moteur_inference(BF base_fait, BC base_connaissance);

bool are_rule_premises_satisfied(Regle rule, BF base_fait);




#endif //PROJET_MOTEUR_INFERENCE_H
