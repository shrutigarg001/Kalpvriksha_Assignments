#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left, *right;
};

void inorderPrint(struct node* root)
{
    if (root != NULL) {
        inorderPrint(root->left);
        printf("%d ", root->value);
        inorderPrint(root->right);
    }
}

struct node* insert(struct node *root, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL) {
        return newnode;
    } else {
        struct node *temp,*prev;
        temp = root;
        while(temp != NULL) {
            if(value < temp->value) {
                prev = temp;
                temp = temp->left;
            } else {
                prev = temp;
                temp = temp->right;
            }
        }
        if(value < prev->value) {
            prev->left = newnode;
        } else {
            prev->right = newnode;
        }
        return root;
    }
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