#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct tree
{
    char data;
    struct tree* left;
    struct tree* right;
}Node;

struct Node *getNode(char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


bool isOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node *buildExpressionTree(char infix[])
{
    Node *stack[100];
    int top = -1;
    for(int i = 0; infix[i]; i++)
    {
        if (isdigit(infix[i]))
        {
            char num[100];
            int j = 0;
            while(isdigit(infix[i]))
            {
                num[j++] = infix[i++];
            }
            num[j] = '\0';
            i--;
            Node * node = newNode(atoi(num));
        }
        
    }
}