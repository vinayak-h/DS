#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to build an expression tree from a postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;
    for (int i = 0; postfix[i]; i++) {
        if (!isOperator(postfix[i])) {
            struct Node* node = newNode(postfix[i]);
            stack[++top] = node;
        } else {
            struct Node* node = newNode(postfix[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top--];
}

// Function to evaluate an expression tree
int evaluateExpressionTree(struct Node* root) {
    if (root) {
        if (!isOperator(root->data))
            return root->data - '0';
        int leftVal = evaluateExpressionTree(root->left);
        int rightVal = evaluateExpressionTree(root->right);
        switch (root->data) {
            case '+':
                return leftVal + rightVal;
            case '-':
                return leftVal - rightVal;
            case '*':
                return leftVal * rightVal;
            case '/':
                return leftVal / rightVal;
        }
    }
    return 0;
}

int main() {
    char postfix[] = "ab+ef*g*-";
    struct Node* root = buildExpressionTree(postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Result: %d\n", evaluateExpressionTree(root));
    return 0;
}