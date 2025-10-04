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

Node* deletesLastNode(Node* head){
    if (head == NULL || head->next ==NULL )return NULL;
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp-> next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}



int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* y = new Node(arr[0],nullptr);
    Node* head = convertArrtoLL (arr);
    deletesLastNode(head);
    Node* temp = head;
    while(temp){
        cout << temp-> data << " ";
        temp = temp-> next;
    }
    
    
}