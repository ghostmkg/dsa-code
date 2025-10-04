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


int main(){
    vector<int> arr = {1,2,3,4,5};
    
    Node* head = convertArrtoLL (arr);
    head = insertHead(head,100);
    cout << head->data << endl;
   
  
    
    
}