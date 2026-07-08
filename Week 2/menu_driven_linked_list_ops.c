#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void print_list(Node* head);
Node* read_list(Node* head, int* size);
Node* create_node(int data);
Node* insert_at_position(Node* head, int pos, int val);
Node* delete_at_position(Node* head, int pos);
int search(Node* head, int key);

int main()
{
    int ch;
    Node* head = NULL;
    int size = 0;

    head = read_list(head, &size);
    system("clear");

    while(1)
    {
        printf("\n------------LINKED LIST OPERATIONS------------\n");
        printf("Current List: ");
        print_list(head);
        printf("\n");
        printf("1. Insert at any position.\n");
        printf("2. Delete at any position.\n");
        printf("3. Search for an element (Linear search).\n");
        printf("-1. Exit.\n");
        scanf("%d", &ch);

        if(ch == -1)
            break;

        switch(ch)
        {
            case 1:
                int insert_pos;
                int insert_val;
                printf("\nEnter a position. (0 - %d): ", size);
                scanf("%d", &insert_pos);
                if(insert_pos < 0 || insert_pos > size)
                {
                    printf("\nInvalid list position\n");
                    break;
                }
                printf("Enter the value to insert at position %d: ", insert_pos);
                scanf("%d", &insert_val);
                head = insert_at_position(head, insert_pos, insert_val);
                size++;
                break;

            case 2:
                int delete_pos;
                printf("\nEnter a position. (0 - %d): ", size-1);
                scanf("%d", &delete_pos);
                if(delete_pos < 0 || delete_pos >= size)
                {
                    printf("\nInvalid array position\n");
                    break;
                }
                head = delete_at_position(head, delete_pos);
                size--;
                break;

            case 3:
                int key;
                printf("\nEnter key to search: ");
                scanf("%d", &key);
                int index = search(head, key);

                if(index == -1)
                    printf("\nValue doesn't exist in List\n");
                else
                    printf("\nValue at position %d\n", index);

                break;

            default:
                printf("\nEnter valid value.\n");
                break;
        }

        getchar();
        printf("\nOperation Succesful\n");
        printf("Press ENTER to clear screen");
        getchar();
        system("clear");
    }
}

void print_list(Node* head)
{
    Node* current = head;

    while(current != NULL)
    {
        printf("%d => ", current->data);
        current = current->next;
    }
    
    printf("NULL");
}

Node* read_list(Node* head, int* size)
{
    int ch = 1;
    Node* current = head;

    while(ch)
    {
        int val;
        printf("Enter a value to append to the list: ");
        scanf("%d", &val);

        Node* new_node = create_node(val);

        if(head == NULL)
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
        
        (*size)++;
        printf("Do you want to continue adding? (1/0): ");
        scanf("%d", &ch);
    }

    return head;
}

Node* create_node(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

Node* insert_at_position(Node* head, int pos, int val)
{
    Node* new_node = create_node(val);

    if(pos == 0)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }
    
    Node* current = head;
    for(int i = 0 ; i < pos-1 ; i++)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;

    return head;
}

Node* delete_at_position(Node* head, int pos)
{
    Node* temp;

    if(pos == 0)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    for(int i = 0 ; i < pos-1 ; i++)
        current = current->next;

    temp = current->next;
    current->next = temp->next;

    free(temp);

    return head;
}

int search(Node* head, int key)
{
    Node* current = head;
    int i = 0;

    while(current != NULL)
    {
        if(current->data == key)
            return i;
        
        current = current->next;
        i++;
    }

    return -1;
}