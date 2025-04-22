#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* insert_anywhere(struct Node* head, int data, int position) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory unavailable\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1 || head == NULL) 
    {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp->next != NULL && count < position- 1) 
    {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

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
    int data, position, choice;

    do 
    {
        printf("Enter a number to insert: ");
        scanf("%d", &data);
        printf("Enter position to insert (1 for beginning, higher for middle/end): ");
        scanf("%d", &position);

        head = insert_anywhere(head, data, position);

        printf("Do you want to insert another node? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Final Linked List: ");
    printList(head);

    return 0;
}
