#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;
        rear->next = front; 
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front; 
    }
    printf("%d inserted into the queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty! Cannot delete.\n");
        return;
    }

    struct Node* temp = front;
    int value = temp->data;

    if (front == rear) { 
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Maintain circular link
    }

    free(temp);
    printf("Deleted element: %d\n", value);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Elements in the Circular Queue: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);
    
    printf("(back to front)\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
