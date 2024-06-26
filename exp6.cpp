#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool parseS(const char *input, int *pos);
bool parseS(const char *input, int *pos) {
    int start_pos = *pos;
    if (input[*pos] == '0') {
        (*pos)++;
        if (parseS(input, pos) && input[*pos] == '1') {
            (*pos)++;
            return true;
        }
        *pos = start_pos; 
    }
    return true;
}
bool is_accepted_by_cfg(const char *input) {
    int pos = 0;
    if (parseS(input, &pos) && input[pos] == '\0') {
        return true;
    }
    return false;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (is_accepted_by_cfg(input)) {
        printf("The string is accepted by the CFG.\n");
    } else {
        printf("The string is rejected by the CFG.\n");
    }
    return 0;
}
