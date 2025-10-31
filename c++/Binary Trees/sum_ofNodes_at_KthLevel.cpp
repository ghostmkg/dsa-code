#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int sumAtKthLevel(Node* root, int k) {
    if (!root) return 0;
    queue<Node*> q;
    q.push(root);
    int level = 0, sum = 0;
    while (!q.empty()) {
        int size = q.size();
        sum = 0;
        for (int i = 0; i < size; i++) {
            Node* curr = q.front(); q.pop();
            if (level == k) sum += curr->data;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        if (level == k) return sum;
        level++;
    }
    return 0;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Sum at level 2: " << sumAtKthLevel(root, 2) << endl;
    return 0;
}