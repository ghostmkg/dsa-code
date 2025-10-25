#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node(int x):val(x),next(NULL){}
};
node* rev(node* h){
    node* p=NULL;
    while(h){
        node* n=h->next;
        h->next=p;
        p=h;
        h=n;
    }
    return p;
}
int main(){
    node* h=new node(1);
    h->next=new node(2);
    h->next->next=new node(3);
    h=rev(h);
    while(h){cout<<h->val<<" ";h=h->next;}
}
