#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    int transitions[3][2]; 
    int start_state;
    int accepting_state;
} DFA;
void initialize_dfa(DFA *dfa) {
    dfa->transitions[0][0] = 1;  
    dfa->transitions[0][1] = -1; 
    dfa->transitions[1][0] = -1; 
    dfa->transitions[1][1] = 2;  
    dfa->transitions[2][0] = -1;
    dfa->transitions[2][1] = -1;
    dfa->start_state = 0; 
    dfa->accepting_state = 2; 
}
bool simulate_dfa(DFA *dfa, const char *input) {
    int current_state = dfa->start_state;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char symbol = input[i];
        int input_index = (symbol == 'a') ? 0 : 1; 
        if (dfa->transitions[current_state][input_index] == -1) {
            return false; 
        } else {
            current_state = dfa->transitions[current_state][input_index];
        }
    }
     return (current_state == dfa->accepting_state);
}
int main() {
    DFA dfa;
    initialize_dfa(&dfa);
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (simulate_dfa(&dfa, input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }
    return 0;
}
