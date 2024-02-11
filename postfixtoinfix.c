#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
// Stack structure and functions
struct Stack {
    int top;
    double items[MAX_SIZE];
};
void initialize(struct Stack *s) {
    s->top = -1;
}
int isEmpty(struct Stack *s) {
    return s->top == -1;
}
void push(struct Stack *s, double value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}
double pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; ++i) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}
double evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i;
    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    double result = evaluatePostfix(postfix);
    printf("Result after evaluation: %.2f\n", result);
    return 0;
}


