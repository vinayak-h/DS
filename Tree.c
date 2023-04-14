#include <stdio.h>
#include <stdlib.h>
typedef struct Tree{
    struct Tree *left, *right;
    int data;
} Node;

Node *getNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *buildBST(Node *root, int val){
    if (root == NULL){
        root = getNode(val);
        return root;
    }
    if (root->data > val){
        root->left = buildBST(root->left, val);
    }else{
        root->right = buildBST(root->right, val);
    }
    return root;
}

void inOrder(Node *root){
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node *root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main(){
    Node * root = NULL;
    int arr[] = {40, 23, 4, 7, 23, 12, 5, 1, 354, 45, 100, 389};
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++)
    {
        root = buildBST(root, arr[i]);
    }

    printf("\nIn-Order Traversal -> ");
    inOrder(root);
    printf("\nPre-Order Traversal -> ");
    preOrder(root);
    printf("\nPost-Order Traversal -> ");
    postOrder(root);
    printf("\n");
    return 0;
}
