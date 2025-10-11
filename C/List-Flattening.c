#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    struct Node* child;
} Node;

void append(Node* child, Node** tail) {
    Node* curNode;

    (*tail)->next = child;
    child->prev = *tail;

    for (curNode = child; curNode->next != NULL; curNode = curNode->next)
        ;

    *tail = curNode;
}

void flattenList(Node* head, Node** tail) {
    Node* curNode = head;

    while (curNode != NULL) {
        if (curNode->child) {
            append(curNode->child, tail);

            curNode->child = NULL;
        }
        curNode = curNode->next;
    }
}

Node* findTail(Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->child = NULL;
    return newNode;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;

    // Create child list for node 1
    head->child = createNode(4);
    head->child->next = createNode(5);
    head->child->next->prev = head->child;

    // Create child list for node 3
    head->next->next->child = createNode(6);

    // Create child list for node 4
    head->child->child = createNode(7);

    // Find initial tail of top level list
    Node* tail = findTail(head);

    flattenList(head, &tail);

    printList(head);

    return 0;
}

/*

Input:

1 <-> 2 <-> 3
|           |
4 <-> 5     6
|
7


Output :

1 2 3 4 5 6 7

*/

