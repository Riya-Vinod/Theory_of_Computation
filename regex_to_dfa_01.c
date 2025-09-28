#include <stdio.h>
#include <string.h>
#define STATES 3
#define SYMBOLS 2

int main() {
    int dfa[STATES][SYMBOLS] = {
        {1, 0}, 
        {1, 2}, 
        {1, 0}  
    };

    int accept = 2;

    char *test_strings[] = {"1101", "111", "0001"};
    int n = 3;

    for (int t = 0; t < n; t++) {
        char *input = test_strings[t];
        int state = 0;
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == '0') state = dfa[state][0];
            else if (input[i] == '1') state = dfa[state][1];
            else {
                printf("%s: Invalid symbol\n", input);
                state = -1;
                break;
            }
        }
        if (state == accept) printf("%s: Accepted\n", input);
        else printf("%s: Rejected\n", input);
    }

    return 0;
}
