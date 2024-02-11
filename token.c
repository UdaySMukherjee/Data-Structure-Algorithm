#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isKeyword(char *token) {
    char *keywords[] = {"int", "char", "float", "double", "long", "short", "void", "signed", "unsigned", "struct", "enum", "union", "const", "volatile"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; ++i) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;  // It's a keyword
        }
    }

    return 0;  // It's not a keyword
}

int isOperator(char *token) {
    char *operators[] = {"++", "--", "+", "-", "*", "/", "%%", "=", "==", "!=", "<", ">", "<=", ">="};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < numOperators; ++i) {
        if (strcmp(token, operators[i]) == 0) {
            return 1;  // It's an operator
        }
    }

    return 0;  // It's not an operator
}

int isSymbol(char *token) {
    char *symbols[] = {",", ";", "(", ")", "[", "]", "{", "}"};
    int numSymbols = sizeof(symbols) / sizeof(symbols[0]);

    for (int i = 0; i < numSymbols; ++i) {
        if (strcmp(token, symbols[i]) == 0) {
            return 1;  // It's a symbol
        }
    }

    return 0;  // It's not a symbol
}

int isNumericValue(char *token) {
    char *endptr;
    strtod(token, &endptr);
    return *endptr == '\0';
}

int main() {
    char input[100];
    char *token; // Declare token as char *

    // Input
    printf("Enter an input: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Tokenize the input
    token = strtok(input, " \t\n\r[],;()"); // Store the pointer returned by strtok in token

    // Process each token
    while (token != NULL) { // Compare token with NULL pointer
        // Check for empty tokens
        if (*token != '\0') { // Dereference token to access the character
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else if (isOperator(token)) {
                printf("Operator: %s\n", token);
            } else if (isNumericValue(token)) {
                printf("Numeric Value: %s\n", token);
            } else if (isSymbol(token)) {
                printf("Symbol: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
        }

        // Get the next token
        token = strtok(NULL, " \t\n\r*[],;()"); // Store the pointer returned by strtok in token
    }

    return 0;
}
