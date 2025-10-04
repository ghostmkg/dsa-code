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

Node* insertBeforeValue(Node* head , int val , int el){
    if (head == NULL){
        return NULL;
        }
    
    if (head->data==el){
        Node* x = new Node(val);
        x->next = head;
        return x;
        
    }

    Node* temp = head;
    while(temp->next!=NULL){
     
        if (temp->next->data == el){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp=temp->next;
        }
        return head;
    }

int main(){
    vector<int> arr = {1,2,3,4,5};
    
    Node* head = convertArrtoLL (arr);
    head = insertBeforeValue(head,10,5);
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
        
    }
}