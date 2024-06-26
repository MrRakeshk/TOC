#include <stdio.h>
#include <string.h>
typedef enum {
    START,
    S0, 
    S1, 
    ACCEPT,
    REJECT
} State;
State transition(State current_state, char input) {
    switch (current_state) {
        case START:
            if (input == '0') return S0;
            else return REJECT;
        case S0:
            if (input == '0') return S0;
            else if (input == '1') return S1;
            else return REJECT;
        case S1:
            if (input == '0') return S0;
            else if (input == '1') return S1;
            else return REJECT;
        default:
            return REJECT;
    }
}
int is_accepted_by_dfa(const char *input) {
    int len = strlen(input);
    State current_state = START;

    for (int i = 0; i < len; i++) {
        current_state = transition(current_state, input[i]);
        if (current_state == REJECT) return 0; // Early reject
    }
    return (current_state == S1);
}
int main() {
    char input[100];   
    printf("Enter a string: ");
    scanf("%s", input);
    if (is_accepted_by_dfa(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }
    return 0;
}
