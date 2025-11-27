// Write a program for binary search tree (BST) having functions for the following
// operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertNode(root->left, val);
    else if (val > root->data) root->right = insertNode(root->right, val);
    // if val == root->data do nothing (no duplicates)
    return root;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + (l < r ? l : r);
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;

    int vals[] = {50, 30, 70, 20, 40, 60, 80, 65};
    for (int v : vals) root = insertNode(root, v);

    cout << "In-order (initial): ";
    inorderPrint(root);
    cout << "\n";

    cout << "Max depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n\n";

    cout << "Insert 55 and 25\n";
    root = insertNode(root, 55);
    root = insertNode(root, 25);
    cout << "In-order: ";
    inorderPrint(root);
    cout << "\nMax depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n\n";

    cout << "Try inserting duplicate 40 (ignored)\n";
    root = insertNode(root, 40);
    cout << "In-order: ";
    inorderPrint(root);
    cout << "\n\n";

    cout << "Delete 70 (node with two children)\n";
    root = deleteNode(root, 70);
    cout << "In-order: ";
    inorderPrint(root);
    cout << "\nMax depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n\n";

    cout << "Delete 20 (leaf)\n";
    root = deleteNode(root, 20);
    cout << "In-order: ";
    inorderPrint(root);
    cout << "\n";

    return 0;
}
