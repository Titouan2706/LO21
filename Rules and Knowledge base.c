// RULES :
// A + B + C + D = E
// A + B = G
// S = C
// H + L = D
// G + E = O
//
// FACTS :
// A
// B
// S
// H
// L
//
//
// CODE TO ADD :
/*
Regle R1 = create_empty_rule();
Regle R2 = create_empty_rule();
Regle R3 = create_empty_rule();
Regle R4 = create_empty_rule();
Regle R5 = create_empty_rule();

R1 = add_condition(R1, 'A');
R1 = add_condition(R1, 'B');
R1 = add_condition(R1, 'C');
R1 = add_condition(R1, 'D');
R1 = create_conclusion(R1, 'E');

R2 = add_condition(R2, 'A');
R2 = add_condition(R2, 'B');
R2 = create_conclusion(R2, 'G');

R3 = add_condition(R3, 'S');
R3 = create_conclusion(R3, 'C');

R4 = add_condition(R4, 'H');
R4 = add_condition(R4, 'L');
R4 = create_conclusion(R4, 'D');

R5 = add_condition(R5, 'G');
R5 = add_condition(R5, 'E');
R5 = create_conclusion(R5, 'O');

base_connaissance = add_rule_to_tail(base_connaissance, R1);
base_connaissance = add_rule_to_tail(base_connaissance, R2);
base_connaissance = add_rule_to_tail(base_connaissance, R3);
base_connaissance = add_rule_to_tail(base_connaissance, R4);
base_connaissance = add_rule_to_tail(base_connaissance, R5);
 */
