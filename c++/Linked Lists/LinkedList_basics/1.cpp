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

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* y = new Node(arr[0],nullptr);
    cout<< y<< endl; // shows the address of the node
    cout << y->data<<endl; //shows the data
    cout << y->next; // shows the next value
    
}