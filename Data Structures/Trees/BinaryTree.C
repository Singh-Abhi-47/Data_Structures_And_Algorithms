#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *Insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (root->left != NULL)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }

    return root;
}

void InOrder(Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

int main()
{
    system("cls");

    struct Node *root = NULL;

    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 70);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 60);
    Insert(root, 80);

    printf("In-order traversal: ");
    InOrder(root);
    printf("\n");

    return 0;
}