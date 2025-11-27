// 4. Write a program to determine whether a given binary tree is a BST or not.

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}

bool isBSTInorder(Node* root) {
    long long prev = numeric_limits<long long>::min();
    bool ok = true;
    // iterative inorder to avoid static state
    struct StackItem { Node* node; bool visited; };
    vector<StackItem> st;
    st.push_back({root, false});
    while (!st.empty() && ok) {
        StackItem it = st.back(); st.pop_back();
        if (!it.node) continue;
        if (it.visited) {
            if (it.node->data <= prev) ok = false;
            prev = it.node->data;
        } else {
            if (it.node->right) st.push_back({it.node->right, false});
            st.push_back({it.node, true});
            if (it.node->left) st.push_back({it.node->left, false});
        }
    }
    return ok;
}

int main() {
    // example 1: valid BST
    Node* root1 = new Node(50);
    root1->left = new Node(30);
    root1->right = new Node(70);
    root1->left->left = new Node(20);
    root1->left->right = new Node(40);
    root1->right->left = new Node(60);
    root1->right->right = new Node(80);

    cout << "Tree1 is " << (isBST(root1) ? "" : "NOT ") << "a BST (min/max method)\n";
    cout << "Tree1 is " << (isBSTInorder(root1) ? "" : "NOT ") << "a BST (inorder method)\n\n";

    // example 2: not a BST
    Node* root2 = new Node(50);
    root2->left = new Node(30);
    root2->right = new Node(70);
    root2->left->left = new Node(20);
    root2->left->right = new Node(60); // violates BST property
    root2->right->left = new Node(55);
    root2->right->right = new Node(80);

    cout << "Tree2 is " << (isBST(root2) ? "" : "NOT ") << "a BST (min/max method)\n";
    cout << "Tree2 is " << (isBSTInorder(root2) ? "" : "NOT ") << "a BST (inorder method)\n";

    return 0;
}
