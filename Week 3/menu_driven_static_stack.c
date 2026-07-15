#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void push(int stack[], int* top, int val)
{
    if(*top == MAX-1)
    {
        printf("Stack is full\n");
        return;
    }

    stack[++(*top)] = val;
}

int pop(int stack[], int* top)
{
    if(*top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[(*top)--];
}

int peek(int stack[], int top)
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top];
}

void display_stack(int stack[], int top)
{
    if(top == -1)
    {
        printf("EMPTY\n");
        return;
    }

    for(int i = top ; i >= 0 ; i--)
        printf("%d ", stack[i]);
    
    printf("\n");
}

int main()
{
    int stack[MAX];
    int top = -1;
    int ch;

    system("clear");

    while(1)
    {
        printf("\n------------STACK OPERATIONS------------\n");
        printf("Current Stack: ");
        display_stack(stack, top);
        printf("1. Push into stack.\n");
        printf("2. Pop top of the stack.\n");
        printf("3. Peek top element.\n");
        printf("-1. Exit.\n");
        scanf("%d", &ch);
        
        if(ch == -1)
            break;

        printf("\n");
        switch(ch)
        {
            case 1:
                int push_val;
                printf("Enter the value to push onto stack: ");
                scanf("%d", &push_val);
                push(stack, &top, push_val);
                break;

            case 2:
                int popped_val = pop(stack, &top);
                if(popped_val == -1)
                    break;
                printf("Popped: %d\n", popped_val);
                break;

            case 3:
                int peek_val = peek(stack, top);
                if(peek_val == -1)
                    break;
                printf("Top element: %d\n", peek_val);
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
