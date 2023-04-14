#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
    char data;
    struct Node *left, *right;
};

struct Node *createNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

struct Node *constructExprTree(char infix[])
{
    struct Node *stack[100];
    int top = -1;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]))
        {
            struct Node *node = createNode(infix[i]);
            stack[++top] = node;
        }
        else if (infix[i] == '(')
        {
            struct Node *node = createNode(infix[i]);
            stack[++top] = node;
        }
        else if (infix[i] == ')')
        {
            while (stack[top]->data != '(')
            {
                struct Node *right = stack[top--];
                struct Node *op = stack[top--];
                struct Node *left = stack[top--];
                op->left = left;
                op->right = right;
                stack[++top] = op;
            }
            top--;
        }
        else
        {
            while (top >= 0 && precedence(infix[i]) <= precedence(stack[top]->data))
            {
                struct Node *right = stack[top--];
                struct Node *op = stack[top--];
                struct Node *left = stack[top--];
                op->left = left;
                op->right = right;
                stack[++top] = op;
            }
            struct Node *node = createNode(infix[i]);
            stack[++top] = node;
        }
    }
    while (top > 0)
    {
        struct Node *right = stack[top--];
        struct Node *op = stack[top--];
        struct Node *left = stack[top--];
        op->left = left;
        op->right = right;
        stack[++top] = op;
    }
    return stack[top];
}

void preorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%c ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}

void postorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%c ", node->data);
}

int main()
{
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    struct Node *root = constructExprTree(infix);
    printf("Preorder traversal of the expression tree: ");
    preorder(root);
    printf("\nInorder traversal of the expression tree: ");
    inorder(root);
    printf("\nPostorder traversal of the expression tree: ");
    postorder(root);
    return 0;
}