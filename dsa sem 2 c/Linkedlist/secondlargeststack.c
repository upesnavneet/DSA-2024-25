#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* push(struct node* top, int data) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) 
    {
        printf("Memory unavailable\n");
        return top;
    }

    newNode->info = data;
    newNode->next = top;
    return newNode;  
}

struct node* pop(struct node* top)
{
    if (top == NULL) 
    {
        printf("Underflow\n");
        return NULL;
    }

    struct node* temp = top;
    printf("Popped element: %d\n", top->info);
    top = top->next;
    free(temp);
    
    return top;
}

void peek(struct node* top) 
{
    if (top == NULL) 
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->info);
}

void display(struct node* top) 
{
    if (top == NULL) 
    {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = top;
    printf("Stack elements:\n");
    printf("top- ");
    while (temp != NULL) 
    {
        printf("%d  ", temp->info);
        temp = temp->next;
    }

}

void second_largest(struct node* top) 
{
    if (top == NULL || top->next == NULL)  
    {
        printf("Not enough elements to find the second largest element");
        return;
    }

    int largest = top->info;
    int s_largest = -1;

    struct node* temp = top->next;
    while (temp != NULL) 
    {
        if (temp->info > largest) 
        {
            s_largest = largest;
            largest = temp->info;
        } 
        else if (temp->info > s_largest && temp->info != largest) 
        {
            s_largest = temp->info;
        }
        temp = temp->next;
    }

    if (s_largest == -1) 
    {
        printf("No second largest element found\n");
    } 
    else 
    {
        printf("Second largest element: %d\n", s_largest);
    }
}

int main() 
{
    struct node* top = NULL;  
    int value, choice;

    while (1) 
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Find Second Largest\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);  
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                peek(top);
                break;

            case 4:
                display(top);
                break;

            case 5:
                second_largest(top);
                break;

            case 6:
                printf("Exiting\n");
                while (top != NULL) 
                {
                    struct node* temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice, try again\n");
        }
    }
}
