#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node 
{
    int sapid;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int getLastThreeDigits(int sapid) {

    return sapid % 1000;
}

int singleDigitSum(int n) 
{
    int sum;
    do {
        sum = 0;
        while (n > 0) 
        {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    } while (sum >= 10);
    return sum;
}

int hashFunction(int sapid) 
{
    int last3 = getLastThreeDigits(sapid);
    int digitSum = singleDigitSum(last3);
    return digitSum % TABLE_SIZE;
}

void insert(int sapid) 
{
    int index = hashFunction(sapid);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sapid = sapid;
    newNode->next = NULL;

    if (hashTable[index] == NULL) 
    {
        hashTable[index] = newNode;
    } 
    else 
    {
        Node* temp = hashTable[index];
        while (temp->next != NULL) 
        {
            if (temp->sapid == sapid) 
            {
                printf("SAP ID %d already exists.\n", sapid);
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        if (temp->sapid == sapid) 
        {
            printf("SAP ID %d already exists.\n", sapid);
            free(newNode);
            return;
        }
        temp->next = newNode;
        printf("Collision handled using separate chaining at index %d.\n", index);
    }

    printf("Inserted SAP ID %d in family %d\n", sapid, index);
}

void search(int sapid) 
{
    int index = hashFunction(sapid);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->sapid == sapid) 
        {
            printf("SAP ID %d found in family %d\n", sapid, index);
            return;
        }
        temp = temp->next;
    }
    printf("SAP ID %d not found\n", sapid);
}

void delete(int sapid) 
{
    int index = hashFunction(sapid);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp != NULL) 
    {
        if (temp->sapid == sapid) 
        {
            if (prev == NULL) \
            {
                hashTable[index] = temp->next;
            } 
            else 
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("SAP ID %d deleted from family %d\n", sapid, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("SAP ID %d not found for deletion\n", sapid);
}

void display() {
    printf("\nHash Table (Separate Chaining):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Family %d: ", i);
        Node* temp = hashTable[i];
        if (temp == NULL) {
            printf("EMPTY");
        }
        while (temp != NULL) {
            printf("%d -> ", temp->sapid);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, sapid;

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter SAP ID to insert: ");
                scanf("%d", &sapid);
                insert(sapid);
                break;
            case 2:
                printf("Enter SAP ID to delete: ");
                scanf("%d", &sapid);
                delete(sapid);
                break;
            case 3:
                printf("Enter SAP ID to search: ");
                scanf("%d", &sapid);
                search(sapid);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
