#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) exit(1);
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void findInRange(struct Node* root, int low, int high) {
    if (root == NULL) return;
    
    if (low < root->data)
        findInRange(root->left, low, high);
        
    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);
        
    if (high > root->data)
        findInRange(root->right, low, high);
}

int main() {
    printf("Name : Khushi Agrawal\n");
    printf("Section : D1\n");
    printf("PRN : 25070521208\n");
    struct Node* root = NULL;
    root = insert(root, 17);
    root = insert(root, 15);
    root = insert(root, 4);
    root = insert(root, 18);
    
    printf("Output: ");
    findInRange(root, 4, 18);
    printf("\n");
    return 0;
}
