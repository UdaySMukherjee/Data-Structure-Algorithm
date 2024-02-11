#include <stdio.h>
#include <string.h>

// Function to tokenize the control flow statement
void tokenizeControlFlow(const char *statement) {
    char *token;
    char copy[100]; // Assuming the input statement won't exceed 100 characters

    // Copy the input statement to a mutable array
    strcpy(copy, statement);

    // Tokenize the statement using strtok
    token = strtok(copy, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }
}

int main() {
    char controlFlowStatement[100];

    // Get user input for the control flow statement
    printf("Enter a control flow statement: ");
    fgets(controlFlowStatement, sizeof(controlFlowStatement), stdin);

    // Remove trailing newline character from user input
    controlFlowStatement[strcspn(controlFlowStatement, "\n")] = 0;

    // Tokenize the control flow statement
    tokenizeControlFlow(controlFlowStatement);

    return 0;
}
