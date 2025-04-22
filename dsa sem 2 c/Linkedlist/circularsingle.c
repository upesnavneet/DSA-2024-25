#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* insert_beginning(struct Node* head, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

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
    return newNode;  
}


struct Node* insert_end(struct Node* head, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

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


struct Node* insert_anywhere(struct Node* head, int target, int data) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return head;
    }

    struct Node* temp = head;
    do {
        if (temp->data == target) 
        {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Target %d not found in the list.\n", target);
    return head;
}


void display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() 
{
    struct Node* head = NULL;
    int choice, value, target;

    while (1) 
    {
        printf("\nCircular Linked List Menu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Specific Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                head = insert_beginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                head = insert_end(head, value);
                break;
            case 3:
                printf("Enter the target value after which to insert: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insert_anywhere(head, target, value);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
