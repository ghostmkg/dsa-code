#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *sortedMerge(Node *head1, Node *head2)
{
    vector<int> arr;

    // pushing the values of the first linked list
    while (head1 != nullptr)
    {
        arr.push_back(head1->data);
        head1 = head1->next;
    }

    // pushing the values of the second linked list
    while (head2 != nullptr)
    {
        arr.push_back(head2->data);
        head2 = head2->next;
    }

    // sorting the vector
    sort(arr.begin(), arr.end());

    // creating a new list with sorted values
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    for (int i = 0; i < arr.size(); i++)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    return dummy->next;
}

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{

    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(40);

    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node *res = sortedMerge(head1, head2);

    printList(res);

    return 0;
}