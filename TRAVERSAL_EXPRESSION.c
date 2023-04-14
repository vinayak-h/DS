#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j, top = -1;
    char stack[100], c;
    for (i = 0, j = 0; infix[i]; i++) {
        c = infix[i];
        if (isdigit(c))
            postfix[j++] = c;
        else if (isOperator(c)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        } else if (c == '(')
            stack[++top] = c;
        else if (c == ')') {
            while (stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
        }
    }
    while (top >= 0)
        postfix[j++] = stack[top--];
    postfix[j] = '\0';
}
Node* buildExpressionTree(char postfix[]) {
    Node* stack[100];
    int top = -1;
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            Node* node = newNode(postfix[i]);
            stack[++top] = node;
        } else if (isOperator(postfix[i])) {
            Node* node = newNode(postfix[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top--];
}

void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL)
        return;
    printf("%c ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infixToPostfix(infix, postfix);
    struct Node* root = buildExpressionTree(postfix);
    printf("\nInfix Expression: %s", infix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Expression Tree:\n");
    displayExpressionTree(root, 0);
    
    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);
    
    printf("\nPostorder Traversal: ");
    postorderTraversal(root);
    
    return 0;
}
