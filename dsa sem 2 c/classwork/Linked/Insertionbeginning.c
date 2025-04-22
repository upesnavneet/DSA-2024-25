#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void insert_beginning(struct Node** head, int newData) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
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
        printf("Enter a number to insert at the beginning: ");
        scanf("%d", &data);
        insert_beginning(&head, data);

        printf("Do you want to insert another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } 
    
    while (choice == 1);

    printf("Final Linked List: ");
    printList(head);

    return 0;
}
