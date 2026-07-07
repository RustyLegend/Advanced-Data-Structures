#include<stdio.h>
#define MAX 100

void read_array(int arr[]);
void print_array(int arr[]);
void insert_at_position(int arr[], int pos, int val);
void delete_at_position(int arr[], int pos);
int search(int arr[], int key);

int n;

int main()
{
    int arr[MAX];
    int ch;

    printf("Enter no.of elements you want to enter (<= 100): ");
    scanf("%d", &n);

    read_array(arr);

    while(1)
    {
        printf("\n------------ARRAY OPERATIONS------------\n");
        printf("Current Array: ");
        print_array(arr);
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
                printf("\nEnter a position. (0 - %d): ", n-1);
                scanf("%d", &insert_pos);
                if(insert_pos < 0 || insert_pos >= n)
                {
                    printf("\nInvalid array position\n");
                    break;
                }
                printf("Enter the value to insert at position %d: ", insert_pos);
                scanf("%d", &insert_val);
                insert_at_position(arr, insert_pos, insert_val);
                break;

            case 2:
                int delete_pos;
                printf("\nEnter a position. (0 - %d): ", n-1);
                scanf("%d", &delete_pos);
                if(delete_pos < 0 || delete_pos >= n)
                {
                    printf("\nInvalid array position\n");
                    break;
                }
                delete_at_position(arr, delete_pos);
                break;

            case 3:
                int key;
                printf("\nEnter key to search: ");
                scanf("%d", &key);
                int index = search(arr, key);

                if(index == -1)
                    printf("\nValue doesn't exist in array\n");
                else
                    printf("\nValue at index %d\n", index);

                break;

            default:
                printf("\nEnter valid value.\n");
                break;
        }
    }
}

void read_array(int arr[])
{
    printf("\n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void print_array(int arr[])
{
    printf("\n");
    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert_at_position(int arr[], int pos, int val)
{
    for(int i = n ; i > pos ; i--)
        arr[i] = arr[i-1];
    
    arr[pos] = val;
    n++;

    printf("\nAfter insertion: ");
    print_array(arr);
}

void delete_at_position(int arr[], int pos)
{
    for(int i = pos ; i < n-1 ; i++)
        arr[i] = arr[i+1];
    
    n--;

    printf("\nAfter deletion: ");
    print_array(arr);
}

int search(int arr[], int key)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == key)
            return i;
    }

    return -1;
}