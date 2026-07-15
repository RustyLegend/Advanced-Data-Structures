#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* create_node(int val)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Malloc failed\n");
        exit(0);
    }

    new_node->data = val;
    new_node->next = NULL;

    return new_node;
}

void print_stack(Node* top)
{
    Node* ptr = top;

    while(ptr != NULL)
    {
        printf("%d => ",ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

void push(Node** top, int val)
{
    Node* new_node = create_node(val);

    if(*top == NULL)
        *top = new_node;
    else
        new_node->next = *top;

    *top = new_node;
}

int pop(Node** top)
{
    if(*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    int val = (*top)->data;
    Node* remove = *top;
    *top = (*top)->next;
    free(remove);
    return val;
}

int peek(Node* top)
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    
    return top->data;
}

int main()
{
    Node* stack = NULL;
    int ch;

    system("clear");

    while(1)
    {
        printf("\n------------STACK OPERATIONS------------\n");
        printf("Current Stack: ");
        print_stack(stack);
        printf("1. Push onto stack.\n");
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
                push(&stack, push_val);
                break;

            case 2:
                int popped_val = pop(&stack);
                if(popped_val == -1)
                    break;
                printf("Popped: %d\n", popped_val);
                break;

            case 3:
                int peek_val = peek(stack);
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
