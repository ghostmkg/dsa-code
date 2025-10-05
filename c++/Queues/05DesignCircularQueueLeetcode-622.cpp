#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue {
public:
    int f;
    int b;
    int s;//curr size
    int c;//capasity
    vector<int>arr;
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        s=0;
        c=k;
        vector<int>v(k);
        arr=v;
    }
    
    bool enQueue(int val) {//push
        if(s==c) return false;
        arr[b]=val;
        b++;
        if(b==c) b=0;
        s++;
        return true;
    }
    
    bool deQueue() {// pop
        if(s==0) return false;
        f++;
        if(f==c) f=0;
        s--;
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        return arr[f];
    }
    
    int Rear() {//back
        if(s==0) return -1;
        if(b==0) return arr[c-1];
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        else return false;
    }
    
    bool isFull() {
         if(s==c) return true;
        else return false;
    }
};

// Example usage:
int main() {
    MyCircularQueue cq(5);
    cout << cq.enQueue(1) << endl; // 1 (true)
    cout << cq.enQueue(2) << endl; // 1 (true)
    cout << cq.enQueue(3) << endl; // 1 (true)
    cout << cq.enQueue(4) << endl; // 1 (true)
    cout << cq.enQueue(5) << endl; // 1 (true)
    cout << cq.enQueue(6) << endl; // 0 (false, queue is full)

    cout << "Front element: " << cq.Front() << endl; // 1
    cout << "Rear element: " << cq.Rear() << endl;   // 5

    cout << cq.deQueue() << endl; // 1 (true)
    cout << cq.enQueue(6) << endl; // 1 (true)

    cout << "Front element: " << cq.Front() << endl; // 2
    cout << "Rear element: " << cq.Rear() << endl;   // 6

    cout << "Is empty: " << cq.isEmpty() << endl; // 0 (false)
    cout << "Is full: " << cq.isFull() << endl;   // 1 (true)

    return 0;
}