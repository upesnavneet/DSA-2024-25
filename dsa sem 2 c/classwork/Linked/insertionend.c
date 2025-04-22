#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* insert_end(struct Node* head, int newdata) 
{
    struct Node* newback = (struct Node*)malloc(sizeof(struct Node));
    if (newback == NULL) 
    {
        printf("Memory unavailable\n");
        return head;
    }

    newback->data = newdata;
    newback->next = NULL;

    if (head == NULL) 
    {
        return newback;
    }

    struct Node* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    temp->next = newback;
    return head;
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* head = NULL;  
    int data, choice;

    do 
    {
        printf("Enter a number to insert at the last: ");
        scanf("%d", &data);
        head = insert_end(head, data);  

        printf("Do you want to insert another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } 
    while (choice == 1);

    printf("Final Linked List: ");
    printList(head);

    return 0;
}
