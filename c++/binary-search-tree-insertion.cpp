#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        cout << "Default Constructor called" << endl;
    }
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//here we pass copy of the original pointer that is pointer to the same location now now 
//we return root that updates the old root value in the main function 
Node *insertion(Node *root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        return root;
    }
    else if (val > root->data)
    {
        //here every time insertion is called for new value 
        root->right = insertion(root->right, val);
    }

    else
    {
        // as if not greater than it will be lesser
        root->left = insertion(root->left, val);
    }
}
//here we directly make changes to the root hence pass by reference 
void BSTInsertion(Node *&root,int data){
    if(root == nullptr){
        root = new Node(data);
    }
    else if(data > root->data){
        BSTInsertion(root->right,data);
    }else{
        BSTInsertion(root->left,data);
    }
}

void levelOrderTraversal(Node *root)
{
    if(root == nullptr){
        cout<<"Empty Tree"<<endl;
        return;
    }
    queue<Node *> q1;
    q1.push(root);
    q1.push(nullptr); // this is for seperation of root value
    while (!q1.empty())
    {
        Node *temp = q1.front();
        q1.pop();
        if (temp == nullptr)
        {
            cout << endl;
            if (!q1.empty())
            {
                q1.push(nullptr);
            }
        }
        else
        {
            cout << temp->data<<" ";
            if (temp->left)
            {
                q1.push(temp->left);
            }
            if (temp->right)
            {
                q1.push(temp->right);
            }
        }
    }
}

void inputData(Node *&root)
{
    cout << "Enter value of to put inside tree : ";
    int val;
    cin >> val;

    while (val != -1)
    {
        root = insertion(root, val);
        cin>>val;
    }
}
int main()
{
    Node *root = nullptr;
    inputData(root);
    levelOrderTraversal(root);
    return 0;
}
//Read this for understanding 
/*
Key Concept in Recursive Call
When we call the function recursively (insertion), val remains the same throughout the recursion because it represents the value we are trying to insert into the tree. The recursive process changes root to traverse the tree, but the value being inserted (val) stays constant for each insertion.

Dry Run with Input: 5, 1, 3, 4, 2, 7
Let's go step-by-step, assuming the following:

We call root = insertion(root, val) for each input value.
root changes during recursion to move left or right in the tree.
val remains the value being inserted in that recursive sequence.
Initial State
Tree is empty, i.e., root = nullptr.
Step 1: Insert 5
Call: root = insertion(root, 5)

root == nullptr, so a new node is created with data = 5.
The tree now looks like this:
Copy code
5
Return the new node as the root.
Step 2: Insert 1
Call: root = insertion(root, 1)

root->data = 5, and val = 1.
Since 1 < 5, recursively call: root->left = insertion(root->left, 1).
root->left == nullptr (left subtree is empty), so a new node is created with data = 1.
The tree now looks like this:
Copy code
  5
 /
1
Step 3: Insert 3
Call: root = insertion(root, 3)

root->data = 5, and val = 3.
Since 3 < 5, recursively call: root->left = insertion(root->left, 3).
Now root->data = 1 (left child of 5), and val = 3.
Since 3 > 1, recursively call: root->right = insertion(root->right, 3).
root->right == nullptr (right subtree of 1 is empty), so a new node is created with data = 3.
The tree now looks like this:
Copy code
  5
 /
1
 \
  3
Step 4: Insert 4
Call: root = insertion(root, 4)

root->data = 5, and val = 4.
Since 4 < 5, recursively call: root->left = insertion(root->left, 4).
Now root->data = 1, and val = 4.
Since 4 > 1, recursively call: root->right = insertion(root->right, 4).
Now root->data = 3, and val = 4.
Since 4 > 3, recursively call: root->right = insertion(root->right, 4).
root->right == nullptr (right subtree of 3 is empty), so a new node is created with data = 4.

*/