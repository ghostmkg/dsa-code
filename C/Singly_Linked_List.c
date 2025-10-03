#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtEnd(Node** head, int data) {
    Node* node = createNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = node;
}

void display(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    display(head);
    return 0;
}
