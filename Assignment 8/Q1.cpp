// Write program using functions for binary tree traversals: Pre-order, In-order and Post
// order using recursive approach.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* createNode(int v) {
    return new Node(v);
}

// Pre-order: Root → Left → Right
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// In-order: Left → Root → Right
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Post-order: Left → Right → Root
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Creating a sample tree:
    //        10
    //       /  \
    //      5    20
    //     / \     \
    //    3   7     30

    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(30);

    cout << "Pre-order: ";
    preorder(root);

    cout << "\nIn-order: ";
    inorder(root);

    cout << "\nPost-order: ";
    postorder(root);

    cout << endl;
    return 0;
}
