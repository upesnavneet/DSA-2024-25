#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* enqueue(struct Node* front, struct Node* rear, int value, struct Node** newRear) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) 
    {
        printf("Memory allocation failed\n");
        return front;
    }
    temp->data = value;
    temp->next = NULL;

    if (front == NULL) 
    {
        front = temp;
    } 
    else 
    {
        rear->next = temp;
    }
    
    *newRear = temp; 
    printf("inserted %d into the queue\n", value);
    return front;
}

struct Node* dequeue(struct Node* front, struct Node* rear, struct Node** newRear) 
{
    if (front == NULL) 
    {
        printf("Queue is empty, cannot dequeue\n");
        return NULL;
    }

    struct Node* temp = front;
    front = front->next;
    printf("deleted %d from the queue\n", temp->data);
    free(temp);

    if (front == NULL) 
    {
        *newRear = NULL;
    }

    return front;
}

void display(struct Node* front) 
{
    if (front == NULL) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (front) 
    {
        printf("%d - ", front->data);
        front = front->next;
    }
}

int main() 
{
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    while (1) 
    {
        printf("\nQueue Operations:\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                front = enqueue(front, rear, value, &rear);
                break;
            case 2:
                front = dequeue(front, rear, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
