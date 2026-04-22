#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int x)
{
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = head;

    head = temp;
}

void insert_end(int x)
{
    struct node *temp, *ptr;

    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void insert_pos(int x,int pos)
{
    struct node *temp,*ptr;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;

    ptr = head;

    for(int i=1;i<pos-1;i++)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_begin()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty");
        return;
    }

    temp = head;

    head = head->next;

    printf("Deleted: %d",temp->data);

    free(temp);
}

void delete_end()
{
    struct node *ptr,*prev;

    if(head == NULL)
    {
        printf("List Empty");
        return;
    }

    ptr = head;

    while(ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;

    printf("Deleted: %d",ptr->data);

    free(ptr);
}

void delete_pos(int pos)
{
    struct node *ptr,*temp;

    ptr = head;

    for(int i=1;i<pos-1;i++)
    {
        ptr = ptr->next;
    }

    temp = ptr->next;

    ptr->next = temp->next;

    printf("Deleted: %d",temp->data);

    free(temp);
}

void search(int key)
{
    struct node *ptr;
    int pos = 1;

    ptr = head;

    while(ptr != NULL)
    {
        if(ptr->data == key)
        {
            printf("Element found at position %d",pos);
            return;
        }

        ptr = ptr->next;
        pos++;
    }

    printf("Element not found");
}

void display()
{
    struct node *ptr;

    ptr = head;

    if(ptr == NULL)
    {
        printf("List Empty");
        return;
    }

    while(ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

int main()
{
    int ch,x,pos;

    do
    {
        printf("\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Insert Position");
        printf("\n4.Delete Beginning");
        printf("\n5.Delete End");
        printf("\n6.Delete Position");
        printf("\n7.Search");
        printf("\n8.Display");
        printf("\n9.Exit");

        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                insert_begin(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d",&x);
                insert_end(x);
                break;

            case 3:
                printf("Enter element and position: ");
                scanf("%d %d",&x,&pos);
                insert_pos(x,pos);
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d",&pos);
                delete_pos(pos);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d",&x);
                search(x);
                break;

            case 8:
                display();
                break;

        }

    }while(ch!=9);

    return 0;
}