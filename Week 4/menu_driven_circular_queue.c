#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void enqueue(int q[], int* front, int* rear, int val)
{
    if(((*rear)+1) % MAX == *front)
    {
        printf("Queue overflow\n");
        return;
    }

    if(*rear == -1)
    {
        *front = 0;
        *rear = 0;
        q[*rear] = val;
        return;
    }

    *rear = (*rear + 1) % MAX;
    q[*rear] = val;
}

int dequeue(int q[], int* front, int* rear)
{
    int dequeue_val = -1;

    if(*front == -1)
    {
        printf("Queue Underflow\n");
        return dequeue_val;
    }

    if(*front == *rear)
    {
        dequeue_val = q[*front];
        *front = -1;
        *rear = -1;
    }
    else
    {
        dequeue_val = q[*front];
        *front = (*front + 1) % MAX;
    }

    return dequeue_val;
}

void display_queue(int q[], int front, int rear)
{
    if(front == -1)
    {
        printf("EMPTY\n");
        return;
    }

    int i = front;
    while(i != rear)
    {
        printf("%d ", q[i]);
        i = (i+1) % MAX;
    }
    
    printf("%d ", q[rear]);

    printf("\n");
}

int main()
{
    int queue[MAX];
    int front = -1;
    int rear = -1;
    int ch;

    system("clear");

    while(1)
    {
        printf("\n------------QUEUE OPERATIONS------------\n");
        printf("Current Queue: ");
        display_queue(queue, front, rear);
        printf("1. Enqueue into queue.\n");
        printf("2. Dequeue from queue.\n");
        printf("-1. Exit.\n");
        scanf("%d", &ch);
        
        if(ch == -1)
            break;

        printf("\n");
        switch(ch)
        {
            case 1:
                int enqueue_val;
                printf("Enter the value to enqueue into queue: ");
                scanf("%d", &enqueue_val);
                enqueue(queue, &front, &rear, enqueue_val);
                break;

            case 2:
                int dequeue_val = dequeue(queue, &front, &rear);
                if(dequeue_val == -1)
                    break;
                printf("Dequeued: %d\n", dequeue_val);
                break;

            default:
                printf("\nEnter valid value.\n");
                break;
        }

        getchar();
        printf("\nOperation Successful\n");
        printf("Press ENTER to clear screen");
        getchar();
        system("clear");
    }
}
