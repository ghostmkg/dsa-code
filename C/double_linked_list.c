#include <stdio.h>
#include <stdlib.h>

// 1. Structure Definition for a Node
// Each node has data, a pointer to the next node, and a pointer to the previous node.
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global head pointer for the list (initialized to NULL)
struct Node* head = NULL;

// Function to create a new Node and allocate memory
struct Node* getNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 2. Insertion at the Head (Beginning)
void InsertAtHead(int x) {
    struct Node* newNode = getNewNode(x);
    
    if (head == NULL) {
        // If the list is empty, the new node is the head
        head = newNode;
        return;
    }
    
    // 1. Link new node's 'next' to the old head
    newNode->next = head;
    
    // 2. Link old head's 'prev' to the new node
    head->prev = newNode;
    
    // 3. Make the new node the head
    head = newNode;
}

// 3. Insertion at the Tail (End)
void InsertAtTail(int x) {
    struct Node* newNode = getNewNode(x);
    
    if (head == NULL) {
        // If the list is empty, the new node is the head
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // 1. Link the last node's 'next' to the new node
    temp->next = newNode;
    
    // 2. Link the new node's 'prev' to the last node
    newNode->prev = temp;
    
    // newNode->next is already NULL (marking the end)
}

// 4. Print all elements in forward order
void PrintForward() {
    struct Node* temp = head;
    printf("Forward List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 5. Print all elements in reverse order
void PrintReverse() {
    struct Node* temp = head;
    
    if (temp == NULL) return; // List is empty
    
    // Traverse to the last node first
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Reverse List: ");
    // Now traverse backward using the 'prev' pointer
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// 6. Main driver code
int main() {
    
    // Insert some elements
    InsertAtHead(1); // List: 1
    InsertAtHead(2); // List: 2 1
    InsertAtTail(3); // List: 2 1 3
    InsertAtTail(5); // List: 2 1 3 5
    InsertAtHead(4); // List: 4 2 1 3 5
    
    // Test Traversal
    PrintForward();  
    PrintReverse(); 
    
    return 0;
}