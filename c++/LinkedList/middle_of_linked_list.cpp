#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

int getLength(Node *head)
{

    int length = 0;

    // Count nodes in linked list
    while (head)
    {
        length++;
        head = head->next;
    }

    return length;
}

int getMiddle(Node *head)
{

    // finding length of the linked list
    int length = getLength(head);

    // traverse till we reached half of length
    int midIndex = length / 2;
    while (midIndex--)
    {
        head = head->next;
    }

    return head->data;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    cout << getMiddle(head);

    return 0;
}