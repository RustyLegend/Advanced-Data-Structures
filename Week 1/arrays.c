#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void read_array(int arr[], int n);
void print_array(int arr[], int n);
void insert_at_position(int arr[], int pos, int val, int n);
void delete_at_position(int arr[], int pos, int n);
int search(int arr[], int key, int n);

int n;

int main()
{
    int arr[MAX];
    int ch;

    printf("Enter no.of elements you want to enter (<= 100): ");
    scanf("%d", &n);

    read_array(arr, n);

    while(1)
    {
        printf("\n------------OPERATIONS------------\n");
        printf("1. Insert at any position.\n");
        printf("2. Delete at any position.\n");
        printf("3. Search for an element (Linear search).\n");
        printf("4. Print current array.\n");
        printf("-1. Exit.\n");
        scanf("%d", &ch);    
        
        if(ch == -1)
            break;

        switch(ch)
        {
            case 1:
                int insert_pos;
                int insert_val;
                printf("Enter a position. (0 - %d): ", n-1);
                scanf("%d", &insert_pos);
                printf("Enter the value to insert at position %d: ", insert_pos);
                scanf("%d", &insert_val);
                insert_at_position(arr, insert_pos, insert_val, n);
                break;

            case 2:
                int delete_pos;
                printf("Enter a position. (0 - %d): ", n-1);
                scanf("%d", &delete_pos);
                delete_at_position(arr, delete_pos, n);
                break;

            case 3:
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = search(arr, key, n);

                if(index == -1)
                    printf("Values doesn't exist in array");
                else
                    printf("Value at index %d", index);

                break;

            case 4:
                printf("Current array: \n");
                print_array(arr, n);
                break;

            default:
                printf("Enter valid value.\n");
                break;
        }
    }
}

void read_array(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void print_array(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
}

void insert_at_position(int arr[], int pos, int val, int n)
{
    for(int i = n ; i <= pos ; i--)
        arr[i-1] = arr[i];
    
    arr[pos] = val;
    n++;

    printf("After insertion: \n");
    print_array(arr, n);
}

void delete_at_position(int arr[], int pos, int n)
{
    for(int i = n-1 ; i >= pos ; i--)
        arr[i-1] = arr[i];
    
    n--;

    printf("After deletion: ");
    print_array(arr, n);
}

int search(int arr[], int key, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == key)
            return i;
    }

    return -1;
}