#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Structure for a binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

// Function to build an expression tree from an infix expression
struct Node* buildExpressionTree(char infix[]) {
    struct Node* stack[100];
    int top = -1;
    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            char num[100];
            int j = 0;
            while (isdigit(infix[i])) {
                num[j++] = infix[i++];
            }
            num[j] = '\0';
            i--;
            struct Node* node = newNode(atoi(num));
            stack[++top] = node;
        } else if (isOperator(infix[i])) {
            struct Node* node = newNode(infix[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        } else {
            printf("Invalid input: %c\n", infix[i]);
            exit(1);
        }
    }
    return stack[top--];
}

// Function to print an expression tree in infix notation
void printInfix(struct Node* root) {
    if (root) {
        if (isOperator(root->data)) {
            printf("(");
            printInfix(root->left);
            printf("%c", root->data);
            printInfix(root->right);
            printf(")");
        } else {
            printf("%d", root->data);
        }
    }
}

int main() {
    char infix[100];
    int choice;
    do {
        printf("Enter an infix expression: ");
        scanf("%s", infix);
        struct Node* root = buildExpressionTree(infix);
        printf("\nExpression tree:\n");
        printInfix(root);
        printf("\n\n1. Enter another expression\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } while (choice != 2);
    return 0;
}

