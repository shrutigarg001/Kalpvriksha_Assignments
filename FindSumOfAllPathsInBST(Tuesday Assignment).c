#include<stdio.h> 
#include<stdlib.h> 

struct node {
    int value; 
    struct node *left, *right; 
}; 

struct node* newNode(int node)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->value = node;
    temp->left = temp->right = NULL;
    return temp;
} 

struct node* insert(struct node* node, int value) {
    if (node == NULL)
        return newNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    return node;
} 

int SumOfAllPath(struct node* root, int ans) { 
    if(root == NULL) {
        return 0; 
    } 
    
    ans = ans + (root -> value); 
    
    if((root -> left == NULL) && (root -> right == NULL)) { 
        return ans;   
    } 
    
    return SumOfAllPath(root->left, ans) + SumOfAllPath(root->right, ans); 
} 

void inorderPrint(struct node* root)
{
    if (root != NULL) {
        inorderPrint(root->left);
        printf("%d ", root->value);
        inorderPrint(root->right);
    }
} 

int main() { 
    struct node* root = NULL;
    root = insert(root, 6);
    insert(root, 3);
    insert(root, 5);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    
    inorderPrint(root); 
    
    printf("\n"); 
    int finalAns = SumOfAllPath(root, 0); 
    printf("Sum Of all Paths: %d", finalAns); 
    return 0; 
}
