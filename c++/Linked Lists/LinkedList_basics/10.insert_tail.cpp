#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArrtoLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover-> next = temp;
        mover = temp;
    }
    return head;
}
Node* insertHead(Node* head,int val){
    Node* x = new Node(val);
    x->next=head;
    return x;
}
Node* insertTail(Node* head, int val){
    Node* x = new Node(val);
    if (head == NULL ) return x;
    Node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
        
    }
    temp->next = x;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    
    Node* head = convertArrtoLL (arr);
    head = insertHead(head,100);
    cout << head->data << endl;
    head = insertTail(head,50);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp=temp->next;
    }
    
    
}