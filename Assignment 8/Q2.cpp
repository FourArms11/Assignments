// Implement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST

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
    else root->right = insertNode(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root) return nullptr;
    if (root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->data == key) return cur;
        cur = (key < cur->data) ? cur->left : cur->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return nullptr;
    if (target->right) return findMin(target->right);

    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return nullptr;
    if (target->left) return findMax(target->left);

    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
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

    cout << "In-order of BST: ";
    inorderPrint(root);
    cout << "\n\n";

    int key = 60;
    Node* r1 = searchRecursive(root, key);
    cout << "Recursive search for " << key << ": " << (r1 ? "Found" : "Not Found") << "\n";

    int key2 = 33;
    Node* r2 = searchIterative(root, key2);
    cout << "Iterative search for " << key2 << ": " << (r2 ? "Found" : "Not Found") << "\n\n";

    Node* mn = findMin(root);
    Node* mx = findMax(root);
    // cout << "Minimum element: " << (mn ? to_string(mn->data) : string("N/A")) << "\n";
    // cout << "Maximum element: " << (mx ? to_string(mx->data) : string("N/A")) << "\n\n";

    int skey = 65;
    Node* succ = inorderSuccessor(root, skey);
    if (succ) cout << "In-order successor of " << skey << " is " << succ->data << "\n";
    else cout << "In-order successor of " << skey << " does not exist or key not found\n";

    int pkey = 20;
    Node* pred = inorderPredecessor(root, pkey);
    if (pred) cout << "In-order predecessor of " << pkey << " is " << pred->data << "\n";
    else cout << "In-order predecessor of " << pkey << " does not exist or key not found\n";

    return 0;
}
