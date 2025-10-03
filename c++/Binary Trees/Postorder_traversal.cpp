#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive Postorder Traversal
void postorderTraversal(Node* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);   // Visit left subtree
    postorderTraversal(root->right);  // Visit right subtree
    cout << root->data << " ";        // Visit root
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

    cout << "Postorder Traversal: ";
    postorderTraversal(root);

    return 0;
}
