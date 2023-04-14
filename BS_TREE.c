#include <stdio.h>
#include <stdlib.h>

//structure
typedef struct tree
{
    struct Node *root;

} tree;

typedef struct Node
{
    struct Node *left, *right;
    int data;
} Node;

Node *getNode(int data)
{   
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *createBST(Node *root, int ele)
{
    if (root == NULL)
    {
        root = getNode(ele);
        return root;
    }
    if (root->data > ele)
    {
        root->left = createBST(root->left, ele);
    }
    else
    {
        root->right = createBST(root->right, ele);
    }
    return root;
}

void preorder_traverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d - ", root->data);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void inorder_traverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder_traverse(root->left);
        printf("%d - ", root->data);
        inorder_traverse(root->right);
    }
}

void postorder_traverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder_traverse(root->left);  
        postorder_traverse(root->right);
        printf("%d - ", root->data);
    }
}


int main()
{
    Node *root = NULL;
    int choice, element;
    do
    {
        printf("\n********TREE MENU********\n");
        printf("\n1.Insert");
        printf("\n2.Pre-Order_Traverse");
        printf("\n3.In-Order_Traverse");
        printf("\n4.Post-Order_Traverse");
        printf("\n5.Exit");

        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            root = createBST(root, element);
            printf("Element inserted successfully.\n");
            break;

        case 2:
            printf("Preorder traversal: ");
            preorder_traverse(root);
            printf("\n");
            break;

        case 3:
            printf("Inorder traversal: ");
            inorder_traverse(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder traversal: ");
            postorder_traverse(root);
            printf("\n");
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}