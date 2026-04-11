#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find elements in range
void findInRange(Node* root, int low, int high, vector<int>& result) {
    if (root == NULL) return;

    // If current node is greater than low, left subtree may have valid nodes
    if (root->data > low) {
        findInRange(root->left, low, high, result);
    }

    // If current node is in range, include it
    if (root->data >= low && root->data <= high) {
        result.push_back(root->data);
    }

    // If current node is less than high, right subtree may have valid nodes
    if (root->data < high) {
        findInRange(root->right, low, high, result);
    }
}

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val); // >= goes right

    return root;
}

// Build BST from array
Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    for (int val : arr) {
        root = insert(root, val);
    }
    return root;
}

// Helper to print result
int main() {


    int inputSize = 0,low,high;
    cout<<"Enter the number of elements in input BST:";
    cin>>inputSize;
    vector<int> input(inputSize);
    cout<<endl<<"Enter the elements of BST"<<endl;
    for(int i=0; i<inputSize; i++)
    {
        cin>>input[i];
    }

    cout<<"Enter the low number:"<<endl;
    cin>>low;
    cout<<"Enter the high number:"<<endl;
    cin>>high;

    Node *root = buildBST(input);
    vector<int> result;
    findInRange(root, low, high, result);

    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

