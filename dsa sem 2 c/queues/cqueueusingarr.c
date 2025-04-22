#include <stdio.h>
#define maxsize 5

int arr[maxsize], rear = -1, front = -1;

void enqueue() 
{
    int n;
    if ((rear + 1) % maxsize == front) 
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element to be inserted: ");
    scanf("%d", &n);
    
    if (rear == -1 && front == -1) 
    {
        rear = front = 0;
    } 
    else 
    {
        rear = (rear + 1) % maxsize;
    }
    arr[rear] = n;
    printf("%d inserted into the queue\n", n);
}

void dequeue() 
{
    if (rear == -1 && front == -1) 
    {
        printf("Queue Underflow! Cannot delete from an empty queue\n");
        return;
    }

    int n = arr[front];
    if (rear == front) 
    {
        rear = front = -1;
    } 
    else 
    {
        front = (front + 1) % maxsize;
    }
    
    printf("Deleted element: %d\n", n);
}

void display() 
{
    if (rear == -1 && front == -1) 
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    printf("Elements in the Circular Queue:\n");
    while (1) 
    {
        printf("%d ", arr[i]);
        if (i == rear) 
            break;
        i = (i + 1) % maxsize;
    }
    printf("\nFront points to: %d\n", arr[front]);
    printf("Rear points to: %d\n", arr[rear]);
}

int main() 
{
    int choice = 0;

    while (choice != 4) 
    {
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) 
        {
            enqueue();
        } 
        else if (choice == 2) 
        {
            dequeue();
        } 
        else if (choice == 3) 
        {
            display();
        } 
        else if (choice == 4) 
        {
            printf("Exiting program\n");
        } 
        else 
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
