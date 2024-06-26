#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    int transitions[4][2][2];
    int start_state;
    int accepting_state;
} NFA;
void initialize_nfa(NFA *nfa) {
    nfa->transitions[0][0][1] = 1; 
    nfa->transitions[1][0][2] = 1;
    nfa->transitions[1][1][1] = 1; 
    nfa->transitions[2][1][3] = 1; 
    nfa->transitions[3][0][1] = 1;
    nfa->transitions[3][1][3] = 1;

    nfa->start_state = 0;
    nfa->accepting_state = 3; 
}
bool simulate_nfa(NFA *nfa, const char *input) {
    int current_states[4] = {0}; 
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        int next_states[4] = {0}; 

        char symbol = input[i];
        int input_index = (symbol == '0') ? 0 : 1;
        for (int j = 0; j < 4; j++) {
            if (current_states[j] == 1) {
                for (int k = 0; k < 2; k++) {
                    if (nfa->transitions[j][input_index][k] == 1) {
                        next_states[k] = 1; 
                    }
                }
            }
        }
        for (int j = 0; j < 4; j++) {
            current_states[j] = next_states[j];
        }
    }
    return (current_states[nfa->accepting_state] == 1);
}

int main() {
    NFA nfa;
    initialize_nfa(&nfa);

    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulate_nfa(&nfa, input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is rejected by the NFA.\n");
    }

    return 0;
}
