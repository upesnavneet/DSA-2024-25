#include<stdio.h>
#define maxsize 10
int queue[maxsize];
int rear=-1, front =0;

void enqueue()
{
    int n;
    if(rear==maxsize-1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("Enter an element: ");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;
    }
}

void dequeue()
{
    int n;
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        n=queue[front];
        printf("Deleted element is %d",n);
        front++;
    }
}

void display()
{
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }  
}

void main()
{
    int choice;
    printf("QUEUE");
    do
    {
        printf("enter 1 for insertion, 2 for deletion, 3 for display and 4 for exit\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;  
            default: printf("End of queue\n");     
        }
    }while(choice != 4);
}