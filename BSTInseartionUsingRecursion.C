#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left, *right;
};

struct node* newNode(int node)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->value = node;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderPrint(struct node* root)
{
    if (root != NULL) {
        inorderPrint(root->left);
        printf("%d ", root->value);
        inorderPrint(root->right);
    }
}

struct node* insert(struct node* node, int value)
{
    if (node == NULL)
        return newNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    return node;
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);

    inorderPrint(root);

    return 0;
} 