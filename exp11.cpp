#include <stdio.h>
#include <stdbool.h>
#define MAX_STATES 10
typedef struct {
    int transitions[MAX_STATES][3][MAX_STATES]; 
    int num_states;
} NFA;
void compute_epsilon_closure(NFA *nfa, int state, bool visited[], bool epsilon_closure[]) {
    visited[state] = true;
    epsilon_closure[state] = true;
    for (int i = 0; i < nfa->num_states; i++) {
        if (nfa->transitions[state][0][i] == 1 && !visited[i]) {
            compute_epsilon_closure(nfa, i, visited, epsilon_closure);
        }
    }
}
void print_epsilon_closures(NFA *nfa) {
    bool visited[MAX_STATES] = {false};
    bool epsilon_closure[MAX_STATES] = {false};
    printf("e-closures for all states:\n");
    for (int i = 0; i < nfa->num_states; i++) {
        for (int j = 0; j < nfa->num_states; j++) {
            visited[j] = false;
            epsilon_closure[j] = false;
        }
        compute_epsilon_closure(nfa, i, visited, epsilon_closure);
        printf("e-closure(%d): {", i);
        bool first = true;
        for (int j = 0; j < nfa->num_states; j++) {
            if (epsilon_closure[j]) {
                if (!first) {
                    printf(", ");
                }
                printf("%d", j);
                first = false;
            }
        }
        printf("}\n");
    }
}
int main() {
    NFA nfa;
    int num_states;
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &num_states);
    nfa.num_states = num_states;
    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < MAX_STATES; k++) {
                nfa.transitions[i][j][k] = 0;
            }
        }
    }
	nfa.transitions[0][0][1] = 1;
    nfa.transitions[1][0][2] = 1;
    nfa.transitions[1][1][3] = 1;
    nfa.transitions[2][0][4] = 1;
    nfa.transitions[3][1][4] = 1;
    print_epsilon_closures(&nfa);
    return 0;
}
