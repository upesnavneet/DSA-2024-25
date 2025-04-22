#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* insert_beginning(struct Node* head, int newData) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory unavailable\n");
        return head;       
    }
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

struct Node* insert_after_key(struct Node* head, int key, int data) 
{
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Key %d not found in the list.\n", key);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory unavailable\n");
        return head;
    }
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insert_end(struct Node* head, int newData) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory unavailable\n");
        return head;
    }
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) 
    {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node* delete_first(struct Node* head)
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* delete_end(struct Node* head)
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) 
    {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) 
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    return head;
}

struct Node* delete_value(struct Node* head, int key)
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->data == key) 
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Value %d not found in the list\n", key);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    if (head == NULL) 
    {
        printf("The list is empty\n");
        return;
    }
    
    printf("Linked List: ");
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
    int data, key, choice;

    while (1) 
    {
        printf("\nLinked List Menu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert After a Specific Value\n");
        printf("3. Insert at End\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Specific Value\n");
        printf("7. Display Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter a number to insert at the beginning: ");
                scanf("%d", &data);
                head = insert_beginning(head, data);
                break;

            case 2:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter a number to insert: ");
                scanf("%d", &data);
                head = insert_after_key(head, key, data);
                break;

            case 3:
                printf("Enter a number to insert at the end: ");
                scanf("%d", &data);
                head = insert_end(head, data);
                break;

            case 4:
                head = delete_first(head);
                break;

            case 5:
                head = delete_end(head);
                break;

            case 6:
                printf("Enter the value to delete: ");
                scanf("%d", &key);
                head = delete_value(head, key);
                break;

            case 7:
                printList(head);
                break;

            case 8:
                printf("Exiting program\n");
                while (head != NULL) 
                {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice, Please try again.\n");
        }
    }

    return 0;
}
