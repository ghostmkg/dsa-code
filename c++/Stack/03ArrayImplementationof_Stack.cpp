#include <iostream>
using namespace std;
class Stack{
public:
    int arr[6];
    int idx;
    Stack(){
        idx=-1;
    }
    void push(int val){
        if(idx==(sizeof(arr)/sizeof(arr[0]))-1){
            cout<<"stack is full";
            return;
        }
        idx++;
        arr[idx]=val;
    }
    void pop(){
        if(idx==-1){
            cout<<"stack is empty";
            return;
        }
        idx--;
    }
    int top(){
        if(idx==-1){
            cout<<"stack is empty";
            return-1;
        }
        return arr[idx];
    }
    int size(){
        return idx+1;
    }
    void display(){
        for(int i=0;i<=idx;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(20);
    st.push(30);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.push(30);
    st.push(30);
    st.display();
}