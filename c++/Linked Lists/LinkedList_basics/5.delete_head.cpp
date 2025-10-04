#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* removesHead(Node* head){
    if (head== NULL) return head;
    Node* temp = head;
    head = head-> next;
    delete temp;
    return head;
}

Node* convert(vector <int>& arr){
    Node* head = new Node(arr[0]);
    Node*mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main(){
    vector <int> hello = {1,2,3,4,5};
    Node* head = convert(hello);
    cout << head-> data;
    head = removesHead(head);
    cout <<head->data;
    
    
}