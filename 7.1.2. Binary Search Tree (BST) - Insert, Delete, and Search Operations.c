#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_OPS 100


typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;    
} Node;


Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


Node* insert(Node *root, int data) {
	if(root == NULL){
		return createNode(data);
	}if(data < root->data){
		root->left = insert(root->left, data);
	}else if(data > root->data){
		root->right = insert(root->right, data);
	}
	return root;
}


Node* findMin(Node *root) {
	while(root != NULL  && root->left != NULL){
		root = root->left;
	}
	return root;
}


Node* deleteNode(Node *root, int key) {
	if(root == NULL){
		return NULL;
	}
	if(key < root->data){
  }
