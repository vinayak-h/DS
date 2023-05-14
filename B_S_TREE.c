#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    struct Node *left, *right;
    int data;
}Node;

Node *getNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = getNode(val);
        return root;
    }
    if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

bool search(Node *root, int val)
{
    if (root == NULL || root->data == val){
        if(root==NULL)
            return false;
        return true;
    }else if(root->data > val){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;
    int choice=1, value;

    do
    {
        printf("\n\n1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value inserted successfully!\n");
            break;

        case 2:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            printf("%s", search(root,value) ? "Value Found" : "Value not found");
            break;

        case 3:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Value deleted successfully!\n");
            break;

        case 4:
            printf("In-order traversal of the tree: ");
            inOrder(root);
            printf("\n");
            break;

        default:
            printf("\nInvalid choice!!");
            break;
        }
    }while(choice!=0);
    return 0;
}

