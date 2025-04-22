#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* insertAtHead(struct Node* head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Overflow\n");
        return head;
    }
    newNode->data = value;

    if (head == NULL) 
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) 
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Overflow\n");
        return head;
    }
    newNode->data = value;

    if (head == NULL) 
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) 
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

struct Node* deleteFromHead(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("Underflow\n");
        return NULL;
    }

    if (head->next == head) 
    {  
        printf("Deleted element = %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next != head) 
    {
        temp = temp->next;
    }

    temp->next = head->next;
    printf("Deleted element = %d\n", head->data);
    struct Node* newHead = head->next;
    free(head);

    return newHead;
}

struct Node* deleteFromEnd(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("Underflow\n");
        return NULL;
    }

    if (head->next == head) 
    {  
        printf("Deleted element = %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != head) 
    {  
        temp = temp->next;
    }

    printf("Deleted element = %d\n", temp->next->data);
    free(temp->next);
    temp->next = head;  
    return head;
}

void display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -  ", temp->data);
        temp = temp->next;
    } while (temp != head);  
    printf("head\n");
}

int main() 
{
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nCircular Linked List Menu\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Head\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at head: ");
                scanf("%d", &value);
                head = insertAtHead(head, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 3:
                head = deleteFromHead(head);
                break;

            case 4:
                head = deleteFromEnd(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice, please enter again\n");
        }
    }
}
