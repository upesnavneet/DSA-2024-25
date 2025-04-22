#include <stdio.h>
#include <stdlib.h>

struct treenode 
{
    int data;
    struct treenode *left, *right;
};

struct treenode* createNode(int data) 
{
    struct treenode* newNode = (struct treenode*)malloc(sizeof(struct treenode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct treenode* insertBST(struct treenode* root, int data) 
{
    if (root == NULL)
        return createNode(data);
    
    if (data <= root->data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);
    
    return root;
}

struct treenode* min(struct treenode* root) 
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct treenode* deleteNode(struct treenode* root, int key) 
{
    if (root == NULL) {
        return root;
    }
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == NULL) 
        {
            struct treenode* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct treenode* temp = root->left;
            free(root);
            return temp;
        }
        struct treenode* temp = min(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct treenode* root) 
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() 
{
    struct treenode* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Display inorder traversal\n");
        printf("3. Delete a number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &data);
                root = insertBST(root, data);
                break;
            case 2:
                if (root == NULL)
                    printf("The tree is empty\n");
                else 
                {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL) 
                {
                    printf("The tree is empty.\n");
                } 
                else 
                {
                    printf("Enter the number to delete: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
