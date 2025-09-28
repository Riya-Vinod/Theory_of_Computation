#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}
void ITP(char* infix, char* postfix) {
    int k = 0;
    for(int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if(isalpha(c)) {
            postfix[k++] = c;
        } else if(c == '(') {
            push(c);
        } else if(c == ')') {
            while(top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while(top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
}
void generate(char* postfix) {
    for(int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if(isalpha(c))
            printf("PUSH %c\n", c);
        else if(c == '+')
            printf("ADD\n");
        else if(c == '-')
            printf("SUB\n");
        else if(c == '*')
            printf("MUL\n");
        else if(c == '/')
            printf("DIV\n");
    }
}
int main() {
    char infix[] = "(a+b)*c";
    char postfix[MAX];
    ITP(infix, postfix);
    printf("Generated Stack Machine Code:\n");
    generate(postfix);
    return 0;
}
