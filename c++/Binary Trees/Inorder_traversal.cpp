#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive Inorder Traversal
void inorderTraversal(Node* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);   // Visit left subtree
    cout << root->data << " ";      // Visit root
    inorderTraversal(root->right);  // Visit right subtree
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);

    return 0;
}
