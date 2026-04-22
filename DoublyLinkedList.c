#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->prev = NULL;
    temp->next = head;

    if(head != NULL)
        head->prev = temp;

    head = temp;
}

void insert_end(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;

    temp->data = x;
    temp->next = NULL;

    if(head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return;
    }

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
}

void insert_pos(int x,int pos)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;

    temp->data = x;

    for(int i=1;i<pos-1;i++)
        ptr = ptr->next;

    temp->next = ptr->next;
    temp->prev = ptr;

    if(ptr->next != NULL)
        ptr->next->prev = temp;

    ptr->next = temp;
}

void delete_begin()
{
    if(head == NULL)
    {
        printf("List Empty");
        return;
    }

    struct node *temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    printf("Deleted: %d",temp->data);

    free(temp);
}

void delete_end()
{
    if(head == NULL)
    {
        printf("List Empty");
        return;
    }

    struct node *ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;

    if(ptr->prev != NULL)
        ptr->prev->next = NULL;
    else
        head = NULL;

    printf("Deleted: %d",ptr->data);

    free(ptr);
}

void delete_pos(int pos)
{
    struct node *ptr = head;

    for(int i=1;i<pos;i++)
        ptr = ptr->next;

    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;

    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    printf("Deleted: %d",ptr->data);

    free(ptr);
}

void search(int key)
{
    struct node *ptr = head;
    int pos = 1;

    while(ptr != NULL)
    {
        if(ptr->data == key)
        {
            printf("Found at position %d",pos);
            return;
        }

        ptr = ptr->next;
        pos++;
    }

    printf("Not found");
}

void display()
{
    struct node *ptr = head;

    if(ptr == NULL)
    {
        printf("List Empty");
        return;
    }

    while(ptr != NULL)
    {
        printf("%d <-> ",ptr->data);
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