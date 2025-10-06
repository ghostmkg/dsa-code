#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// -------------------- LEVEL ORDER (BFS) --------------------
void levelOrderQueue(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// -------------------- ITERATIVE PREORDER (Root-Left-Right) --------------------
void iterativePreOrder(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        cout << temp->val << " ";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }
    cout << endl;
}

// -------------------- ITERATIVE INORDER (Left-Root-Right) --------------------
void iterativeInOrder(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

// -------------------- ITERATIVE POSTORDER (Left-Right-Root) --------------------
void iterativePostOrder(Node* root) {
    if (!root) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left) st1.push(temp->left);
        if (temp->right) st1.push(temp->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->val << " ";
        st2.pop();
    }
    cout << endl;
}

// -------------------- TREE CONSTRUCTION --------------------
Node* construct(int arr[], int n) {
    if (n == 0) return NULL;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* temp = q.front();
        q.pop();

        if (i < n && arr[i] != INT_MIN) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i < n && arr[i] != INT_MIN) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

// -------------------- MAIN --------------------
//                            1
//                          /   \
//                         2     3
//                        / \    /
//                       4   5  6
//                      /     \ / \
//                     6      7 8  9

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9, INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = construct(arr, n);

    cout << "Level Order: ";
    levelOrderQueue(root);

    cout << "Preorder: ";
    iterativePreOrder(root);

    cout << "Inorder: ";
    iterativeInOrder(root);

    cout << "Postorder: ";
    iterativePostOrder(root);

    return 0;
}
