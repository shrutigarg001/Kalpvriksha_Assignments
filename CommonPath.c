#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[10];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int Path(struct Node* root, int index, char** path, char* value) {
    if (root == NULL)
        return 0;

    strcpy(path[index], root->data);
    if (strcmp(root->data, value) == 0) {
        return 1;
    }

    if (Path(root->left, value, path, index + 1) ||
        Path(root->right, value, path, index + 1)) {
        return 1;
    }

    path[index][0] = '\0';
    return 0;
}

void CommonAreas(struct Node* root, char* Corporation1, char* Corporation2) {
    char* path1[10];
    char* path2[10];

    for (int i = 0; i < 10; i++) {
        path1[i] = (char*)malloc(10 * sizeof(char));
        path2[i] = (char*)malloc(10 * sizeof(char));
    }

    Path(root, Corporation1, path1, 0);
    Path(root, Corporation2, path2, 0);

    
    int i = 0, j = 0;
    while (path1[i][0] != '\0' && path2[j][0] != '\0') {
        if (strcmp(path1[i], path2[j]) == 0) {
            printf("%s", path1[i]);
            if (path1[i + 1][0] != '\0' || path2[j + 1][0] != '\0') {
                printf(", ");
            }
            i++;
            j++;
        } else if (strcmp(path1[i], path2[j]) < 0) {
            i++;
        } else {
            j++;
        }
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        free(path1[i]);
        free(path2[i]);
    }
}

int main() {
    struct Node* root = createNode("Bangalore");

    root->left = createNode("Bangalore West");
    root->right = createNode("Bangalore East");
    
    root->right->left = createNode("A");
    root->right->right = createNode("B");

    root->left->left = createNode("C");
    root->left->right = createNode("D");

    root->right->left->left = createNode("56001");
    root->right->left->right = createNode("56002");

    root->right->right->left = createNode("56003");
    root->right->right->right = createNode("56004");

    root->left->left->left = createNode("56005");
    root->left->left->right = createNode("56006");

    root->left->right->left = createNode("56007");
    root->left->right->right = createNode("56008");

    char Corporation1[10];
    char Corporation2[10];

    printf("Enter Corporation code 1: ");
    scanf("%s", Corporation1);
    printf("Enter Corporation code 2: ");
    scanf("%s", Corporation2);

    printf("Output:\n");
    CommonAreas(root, Corporation1, Corporation2);

    return 0;
}
