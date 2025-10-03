#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
    int f;
    int b;
    vector<int>arr;
    Queue(int val){
        f = 0;
        b = 0;
        vector<int>v(val);
        arr=v;
    }
    void push(int val){
        if(b==5){
            cout<<"Queue is FULL"<<endl;
            return;
        }
        arr[b]=val;
        b++;
    }
    void pop(){
        if(f-b==0){
            cout<<"Queue is EMPTY!"<<endl;
            return;
        }
        f++;
    }
    int front(){
        if(f-b==0){
            cout<<"Queue is EMPTY!"<<endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(f-b==0){
            cout<<"Queue is EMPTY!"<<endl;
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        if(f-b==0) return true;
        else return false;
    }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q(5); //push pop front back size empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.display();
    cout<< q.size();
}