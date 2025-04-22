#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void insert(struct Node table[], int size, int key) 
{
    int index = key % size;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = table[index].next;
    table[index].next = newNode;
}

void display(struct Node table[], int size) 
{
    int i;
    for (i = 0; i < size; i++) {
        printf("Index %d: ", i);
        struct Node* temp = table[i].next;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() 
{
    int size, choice, value, i;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    struct Node* hashTable = (struct Node*)malloc(size * sizeof(struct Node));

   
    for (i = 0; i < size; i++) 
    {
        hashTable[i].next = NULL;
    }

    while (1) 
    {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) 
        {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(hashTable, size, value);
        } 
        else if (choice == 2) 
        {
            display(hashTable, size);
        } 
        else if (choice == 3) 
        {
            break;
        } 
        else 
        {
            printf("Invalid choice\n");
        }
    }

    for (i = 0; i < size; i++) 
    {
        struct Node* temp = hashTable[i].next;
        while (temp != NULL) 
        {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(hashTable);

    return 0;
}