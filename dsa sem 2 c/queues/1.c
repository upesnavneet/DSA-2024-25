#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct 
{
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}
s
typedef struct 
{
    Stack stack1;
    Stack stack2;
} Queue;


void initQueue(Queue *q) 
{
    initStack(&q->stack1);
    initStack(&q->stack2);
}

void enqueue(Queue *q, int value) 
{
    push(&q->stack1, value);
    printf("Enqueued: %d\n", value);
}
int dequeue(Queue *q) 
{
    if (isEmpty(&q->stack2)) 
    {
        while (!isEmpty(&q->stack1)) 
        {
            push(&q->stack2, pop(&q->stack1));
        }
    }

    if (isEmpty(&q->stack2)) 
    {
        printf("Queue is empty\n");
        return -1;
    }

    return pop(&q->stack2);
}

int main() 
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 40);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
