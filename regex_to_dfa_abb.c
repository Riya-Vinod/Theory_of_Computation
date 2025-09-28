#include <stdio.h>
#include <string.h>
#define STATES 4
#define SYMBOLS 2

int main() {
    int dfa[STATES][SYMBOLS] = {
        {1, 0},
        {1, 2},
        {1, 3},
        {1, 0}
    };

    int accept = 3;

    printf("DFA Transition Table for (a|b)*abb:\n");
    printf("State\\Input  a  b\n");
    for (int i = 0; i < STATES; i++) {
        printf("q%d          q%d  q%d\n", i, dfa[i][0], dfa[i][1]);
    }

    char input[100];
    printf("\nEnter string to validate: ");
    scanf("%s", input);

    int state = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') state = dfa[state][0];
        else if (input[i] == 'b') state = dfa[state][1];
        else {
            printf("Invalid symbol!\n");
            return 0;
        }
    }

    if (state == accept) printf("Accepted\n");
    else printf("Rejected\n");

    return 0;
}
