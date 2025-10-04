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
Node* convertArr2LL(vector <int> & arr){
    Node* head= new Node(arr[0]);
    Node* mover = head;
    for (int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
        return head;
    }

int checkIfPresent(Node*head, int val){
    int count=0;
    Node* temp = head;
    while(temp){
        if (temp->data == val){
            return 1;
        }
        temp = temp-> next;
        count++;
    }
    return 0;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    cout << checkIfPresent(head,5);
    
}