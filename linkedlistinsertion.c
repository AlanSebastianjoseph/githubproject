#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty, new node becomes the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;  // Empty list

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    displayList(head);

    return 0;
}
