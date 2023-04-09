#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left, *right;
};

int search(struct node* root, int value)
{
    if (root == NULL)
        return 0; 
    else if (root->value == value)
        return 1;
    else if (value < root->value)
        return search(root->left, value);
    else 
        return search(root->right, value);
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
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int a = search(root, 70); 
    printf("%d", a); 
    return 0;
} 