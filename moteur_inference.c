
#include "moteur_inference.h"
#include "stdio.h"

bool are_rule_premises_satisfied(Regle rule, BF base_fait) {
    premisse* current_premise = rule->condition;

    // Iterate through all premises of the rule
    while (current_premise != NULL) {
        char prop = current_premise->prop;

        // Check if the premise is satisfied in the fact base
        if (!is_fact_in_base(base_fait, prop)) {
            return false;  // If any premise is not satisfied, return false
        }

        current_premise = current_premise->next;  // Move to the next premise
    }

    return true;  // All premises are satisfied
}


BF moteur_inference(BF base_fait, BC base_connaissance){
    if (base_fait == NULL || base_connaissance == NULL) {
        return base_fait;  // If either base is empty, no inference can be performed
    }

    // Iterate through each rule in the knowledge base
    BC current_rule = base_connaissance;
    while (current_rule != NULL) {
        Regle rule = current_rule->rule;

        // Check if all premises of the rule are satisfied in the fact base
        if (!is_premise_empty(rule) && are_rule_premises_satisfied(rule, base_fait)) {
            // Add the conclusion to the fact base if not already present
            char conclusion = access_conclusion(rule);
            if (!is_fact_in_base(base_fait, conclusion)) {
                base_fait = add_fact_to_tail(base_fait, conclusion);
            }
        }

        current_rule = current_rule->next;  // Move to the next rule
    }

    return base_fait;  // Return the modified fact base
}