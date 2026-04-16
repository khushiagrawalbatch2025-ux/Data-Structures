#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int isBalanced(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), s[i])) {
                return 0;
            }
        }
    }
    return (top == -1); 
}

int main() {
    printf("Name : Khushi Agrawal\n");
    printf("Section : D1\n");
    printf("PRN : 25070521208\n");
    printf("\n");
    
    char expr[100];
    printf("Enter expression: ");
    scanf("%s", expr);
    
    if (isBalanced(expr))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
